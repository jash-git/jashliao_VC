#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "rasheadr.h"

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif
//---------------------------------------------

struct aPoint {
   int x;  // x coord of point in pixel map
   int y;  // y coord of point in pixel map
   int id; // id of stroke to which point belongs
   };

struct aPoint point[1024];

char Grid[1024][1024];

int ReadStrokeFile(char *InName,long& maxx, long& maxy,int InvFlag){
   FILE *fpIn;
   char Name[180];
   char command[180];
   int  count,dun,sid;
   int  i,x,y,xyindx;
   long minx,miny;
strcpy(Name,InName);
strcat(Name,".RAW");
minx=65535; miny=65535;
if((fpIn = fopen(Name,"r")) == NULL){
   printf("Unable to open input file:%s",InName);
   return 0;
   }
sid=0; xyindx=0; dun=0;
while (!dun) {
   fscanf(fpIn,"%s",command);
   if (strcmp("=S",command)==0) {
       fscanf(fpIn,"%d",&count);
       for (i=0; i<count; i++) {
          fscanf(fpIn,"%d%d",&x,&y);
          point[xyindx].x=x;
          point[xyindx].y=y;
          point[xyindx].id=sid;
          xyindx++;
          minx=min(minx,x);
          miny=min(miny,y);
          } /* endfor */
       sid++;
       }
     else {
       if (strcmp("=E",command)==0) dun=1;
       if (feof(fpIn)) dun=1;
       } /* endif */
   } /* endwhile */
maxx=0; maxy=0;
for (i=0; i<xyindx; i++) {  //shift image to remove
   if(sid != point[i].id)   //excess space
      sid  = point[i].id;
   point[i].x=point[i].x-minx;
   point[i].y=point[i].y-miny;
   maxx=max(maxx,point[i].x);
   maxy=max(maxy,point[i].y);
   } /* endfor */
if(InvFlag)   //optionally invert for screen coord system.
   for (i=0; i<xyindx; i++) {       
      point[i].y=maxy-point[i].y; } 
fclose(fpIn);
return xyindx; //return number of entries in point array
}

void PlotOnGrid(int x0, int y0, int x1, int y1){
   double m,b,rx,ry,rx0,rx1,ry0,ry1,rlasty;
   int xStart,yStart,xEnd,yEnd;
   int x,y;
//plot a line between points [x0,y0] & [x1,y1]
Grid[x0][y0]=1;
Grid[x1][y1]=1;
if (x1==x0) { //handle vert line as special case
   if (y0>y1) {
      yStart=y1; yEnd=y0; }
     else {
      yStart=y0; yEnd=y1; }
   for (y=yStart; y<=yEnd; y++) {
      Grid[x0][y]=1; } /* endfor */
   }
 else {
   ry0=(double)y0;
   rx0=(double)x0;
   ry1=(double)y1;
   rx1=(double)x1;
   xStart=min(x0,x1);
   xEnd=max(x0,x1);
   m=(ry1-ry0)/(rx1-rx0);     //calc slope
   b=ry0-m*rx0;               //calc intercept
   rlasty=-1.0;
   for (x=xStart; x<=xEnd; x++) {
      rx= (double)x;
      ry=m*rx+b;
      if (rlasty>=0.0){
         if (ry<rlasty) {
            for (y=(int)ry; y <= rlasty; y++) {
               Grid[x][y]=1;
               } /* endfor */
            }
          else {
            for (y=(int)rlasty; y <= ry; y++) {
               Grid[x][y]=1;
               } /* endfor */
            } /* endif */
         rlasty=ry;
         }
       else {
         Grid[x][(int)ry]=1;
         rlasty=ry;
         }
      } /* endfor */
   } /* endif */
}

int  SaveGridAsRAS(char *OutName,int maxx, int maxy){
   FILE              *fpOut;
   struct rasterfile rasterhdr;
   int               filesize,BytesPerLine,i,j,k;
   int               width,height;
   unsigned char     *data;
   unsigned char     mask;
   int               CurrByte;
   int               x, pelval;
   double            Scale,S1,S2;
   char              Name[180];
strcpy(Name,OutName);
strcat(Name,".RAS");
if((fpOut = fopen(Name,"wb")) == NULL)
      return 0;
width=maxx;    height=maxy;
while (8*(width/8) != width) {
   width++;
   } /* endwhile */
rasterhdr.ras_width = width;
rasterhdr.ras_height= height;
filesize = (width>>3) * height;
BytesPerLine=(width>>3);                           
data = new unsigned char[filesize];
// load data from Grid and store in ras file buf
mask=0x80;
for (i=0; i<height; i++) {
   for (j=0; j<BytesPerLine; j++) {
      CurrByte=0;
      for (k=0; k<8; k++) {
         if(Grid[8*j+k][i]!=0 )
           CurrByte = CurrByte | (mask>>k);
         }
      data[i*BytesPerLine + j] = CurrByte;
      }
   }
fwrite(&rasterhdr,sizeof(struct rasterfile),1,fpOut);
fwrite(data,1,filesize,fpOut);
delete data;
fclose(fpOut);
return 1;
}

void PlotStrokes(int xyPoints){
   int sid,xprev,yprev,i;
sid=-1;
//Now map all strokes onto a 2 dim grid
for (i=0; i<xyPoints; i++) {
   if(sid != point[i].id)    //seed. must wait til a prev stroke exists
      sid  = point[i].id;
    else  
      PlotOnGrid(xprev,yprev,point[i].x,point[i].y);  //plot it
   xprev=point[i].x;         //curr stroke becomes previous stroke
   yprev=point[i].y;
   } /* endfor */
}

int main(int argc, char *argv[]) {
   int xyPoints;
   long Maxx,Maxy;
xyPoints=ReadStrokeFile(argv[1],Maxx,Maxy,1);  //Read in strokes from stroke file
PlotStrokes(xyPoints);                         //Plot strokes on grid.
if (SaveGridAsRAS(argv[1],Maxx,Maxy)==0)       //Now save the grid as a ras
   printf("Save as pixel map failed!!");
return 1;
}
