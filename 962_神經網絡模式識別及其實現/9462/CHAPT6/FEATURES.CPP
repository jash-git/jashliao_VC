#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "prep.h"


struct tgrid {
   int x;
   int y;
};
struct tLoop {
   int x; // Center of mass X coord
   int y; // Center of mass Y coord
   int m; // Total Mass (Useful to disqualify ornamentation
};

struct tMap{
   int Pel;
   int Next1;
   int Next2;
};

#include "coordq.cpp"

class cThinner {
private:
  int     xMax, yMax; // Size of the bitmap
  int     PelxMax, PelyMax;
  int     PelxMin, PelyMin;
  int     M[32][32];  // Space for the whole bitmap
  int     Stage1[32][32];  // orig image archive
  int     Stage2[32][32];  // loop image archive
  int     W[32][32];  // Work Space save area
  int     M1[3][3];   // 3x3 receptive field -- Template sized window
  tMap    Map[7];
  tgrid   ZeroPosn[4];
  int     ApplyTemplate(int, int, int);
  void    Rotate(int);
  int     isConnected();
  void    buildMap();
  int     isPath(int, int);
  int     isEndPt(int, int);
  int     isIntersect(int, int);
  int     isIntersect2(int, int);
  int     WeakCond(int x, int y);
  int     StrongCond(int x, int y);
  int     EndPtCnt;            // number of end points
  tgrid   EndPoint[324];       // endpoint coords
  int     IntPtCnt;            // number of intersects
  tgrid   IntersectPoint[324]; // intersect coords
  int     LoopCnt;
  tLoop   LoopLocation[324];
  int  Stubs1();
  int  Stubs2(int x1, int y1,int x2,int y2);
  int ValidZeroChild(int, int, int, int);
  void Frame2Ones();
  void NQZeroes(coordq *, tgrid);
  void KillOneLoop(int&, int&, int&);// deal w/ 1 loop 

public:
  cThinner();
  void    SetGridSize(int Mx, int My){xMax=Mx; yMax=My;}
  void    Store(int x,int y,int Pel){Stage1[x][y]=M[x][y]=Pel;}
  int     QueryPel(int x,int y){return M[x][y];}
  void    Thin1();
  void    Thin2();
  int     doScan(int);
  void    ShowM();
  void    ShowW();
  void    Show2(FILE *);
  void    fShowM(FILE *);
  void    ShowM1();
  void    ShowMap();
  void    LocateEndPts();
  void    LocateIntersects();
  void    SetCharExtents();
  int     doScanLR();
  int     doScanInOut();
  int     ApplyAllTemplates(int, int);
  int     QueryEndCount(){return  EndPtCnt;}
  int     QueryIntCount(){return  IntPtCnt;}
  tgrid   QueryEndPoint(int n);
  tgrid   QueryIntPoint(int n);
  void    KillStubs();
  void    Grid2Work();   //save pixel map in work buffer
  void    Work2Grid();   //save pixel map in work buffer
  void    Grid2Stage2();   //save pixel map in work buffer
  int     isLoop();      //1= there are loops 0=no loops
  void    LocateLoops(); //find all independent loops
                         //work buf is left w/ Endpoints excised
  int     QueryLoopCnt(){return LoopCnt;}
  tLoop   QueryLoop(int k){return LoopLocation[k];}//returns info re Nth loop
  int     FindNeighbor(int&, int &);
  void    Kill1Path(int);
  void    KillEndPaths();
  void    IsolatedPelcleanup();
  int     isAnyPelOn();
  int     isAnyPelOff(int&, int&);
  void    ShowLoops(FILE *);
};


//********************************************************
// Copy fns between pixel map & temporary work space.    *
//********************************************************

void cThinner::Grid2Stage2(){
int x,y;
for (x=0; x<xMax; x++) {
   for (y=0; y<yMax; y++) {
      Stage2[x][y]=M[x][y];
      } /* endfor */
   } /* endfor */
}

void cThinner::Grid2Work(){
int x,y;
for (x=0; x<xMax; x++) {
   for (y=0; y<yMax; y++) {
      W[x][y]=M[x][y];
      } /* endfor */
   } /* endfor */
}


void cThinner::Work2Grid(){
int x,y;
for (x=0; x<xMax; x++) {
   for (y=0; y<yMax; y++) {
      M[x][y]=W[x][y];
      } /* endfor */
   } /* endfor */
}

//******************************************************** 
//Deletes pel iff all surrounding pells are zero
//********************************************************
void cThinner::IsolatedPelcleanup() {
int x,y;
for (x=0; x<xMax; x++) {
   for (y=0; y<yMax; y++) {
      if (M[x][y]==1){      // faster than a for loop
         if ( (M[x-1][y-1]==0) && (M[x-1][y]==0) && (M[x-1][y+1]==0) && (M[x][y-1]==0)
            && (M[x][y+1]==0) && (M[x+1][y-1]==0) && (M[x+1][y]==0) && (M[x+1][y+1]==0)  )
             M[x][y]=0;
         }
      } /* endfor */
   } /* endfor */
}

//********************************************************
// Returns 1 if there is a nearest neighbor 1 pel to x,y *
//         0 otherwise                                   *
// also modifies x,y to be the neighbors coord           *
//********************************************************
int cThinner::FindNeighbor(int& x, int& y){
  int i,j;
for (i=0; i<3; i++) {
   for (j=0; j<3; j++) {
      if (M[x-1+i][y-1+j]==1) {
         x=x-1+i; y=y-1+j;
         return 1;
         } /* endif */
      } /* endfor */
   } /* endfor */
return 0;
}


int cThinner::isAnyPelOn(){
int x,y;
for (x=0; x<xMax; x++) {
   for (y=0; y<yMax; y++) {
      if (M[x][y]==1) return 1;
      } /* endfor */
   } /* endfor */
return 0;
}

int cThinner::isAnyPelOff(int& x, int& y){

for (x=0; x<xMax; x++) {
   for (y=0; y<yMax; y++) {
      if (M[x][y]==0) return 1;
      } /* endfor */
   } /* endfor */
return 0;
}

//********************************************************
// Starting at a given endpoint eliminate all pels until *
// either:                                               *
//         A) Another endpoint is encountered (inclusive)*
//    or                                                 *
//         B) An Intersect is encountered  (exclusive)   *
//********************************************************

void cThinner::Kill1Path(int EPindx){
   int x,y;
   int Done;
x = EndPoint[EPindx].x;
y = EndPoint[EPindx].y;
Done=0;
while (!Done) {
   M[x][y] = 0;  // kill the current pel
   if (!FindNeighbor(x,y)) Done =1; //No neighbor found...we're done
   if (isEndPt(x,y)) {   //check whether x,y is an endpoint
      M[x][y]=0; //endpoint<->endpoint delete is inclusive
      Done=1;
      }
   if (isIntersect2(x,y)) Done=1;
   } /* endwhile */
}

void cThinner::KillEndPaths(){
  int i;
for (i=0; i<EndPtCnt; i++) {
   if(M[EndPoint[i].x][EndPoint[i].y])
      Kill1Path(i);
} /* endfor */
}

void cThinner::KillStubs(){
  while (Stubs1()) {
     LocateEndPts();     
     LocateIntersects(); 
  } /* endwhile */
}

int  cThinner::Stubs1(){
  int ix,iy,ex,ey,i,j,rc;
for (i=0; i<EndPtCnt; i++) {
   for (j=0; j<IntPtCnt; j++) {
      ex= EndPoint[i].x;
      ey= EndPoint[i].y;
      ix=IntersectPoint[j].x;
      iy=IntersectPoint[j].y;
      if ( (abs(ex-ix)<=2) && (abs(ey-iy)<=2)) {
         //printf("\n**************DIRTY**************\n");
         rc=Stubs2(ex,ey,ix,iy);
         if (rc) return 1;
         } /* endif */
      } /* endfor */
   } /* endfor */
return 0;
}

int  cThinner::Stubs2(int x1, int y1,int x2,int y2){
   int i,j,k,l;
   for (i=x1-1; i<=x1+1; i++) {
      for (j=y1-1; j<=y1+1; j++) {
         if( !((i==x1) && (j==y1)) ){
            for (k=x2-1; k<=x2+1; k++) {
               for (l=y2-1; l<=y2+1; l++) {
                  if ((i==k)&&(j==l)&&(M[i][j]==1) && !((k==x2) && (l==y2))) {
                     M[i][j]=0;      // deletes occur when both have same neighbor
                     M[x1][y1]=0;
                     return 1;
                     } /* endif */
                  } /* endfor */
               } /* endfor */
            } //endif
         } /* endfor */
      } /* endfor */
   return 0;
}

cThinner::cThinner(){
  ZeroPosn[0].x=1;  ZeroPosn[0].y=0; // SOUTH
  ZeroPosn[1].x=2;  ZeroPosn[1].y=1; // EAST
  ZeroPosn[2].x=1;  ZeroPosn[2].y=2; // NORTH
  ZeroPosn[3].x=0;  ZeroPosn[3].y=1; // WEST
  Map[0].Next1= 1;  Map[0].Next2=-1;
  Map[1].Next1= 3;  Map[1].Next2= 2;
  Map[2].Next1= 3;  Map[2].Next2=-1;
  Map[3].Next1= 5;  Map[3].Next2= 4;
  Map[4].Next1= 5;  Map[4].Next2=-1;
  Map[5].Next1= 6;  Map[5].Next2=-1;
  Map[6].Next1=-1;  Map[6].Next2=-1;
}
/*
void cThinner::Setup(){
  ZeroPosn[0].x=1;  ZeroPosn[0].y=0; // SOUTH
  ZeroPosn[1].x=2;  ZeroPosn[1].y=1; // EAST
  ZeroPosn[2].x=1;  ZeroPosn[2].y=2; // NORTH
  ZeroPosn[3].x=0;  ZeroPosn[3].y=1; // WEST
  Map[0].Next1= 1;  Map[0].Next2=-1;
  Map[1].Next1= 3;  Map[1].Next2= 2;
  Map[2].Next1= 3;  Map[2].Next2=-1;
  Map[3].Next1= 5;  Map[3].Next2= 4;
  Map[4].Next1= 5;  Map[4].Next2=-1;
  Map[5].Next1= 6;  Map[5].Next2=-1;
  Map[6].Next1=-1;  Map[6].Next2=-1;
}
*/
void cThinner::Thin1(){
  int Tid;
  int dirty;
SetCharExtents();
dirty=1;
while (dirty) {
   dirty=doScanInOut();
   } /* endwhile */
}

void cThinner::Thin2(){
  int dirty;
dirty=1; 
while (dirty) {
   dirty =doScan(1);
   dirty+=doScan(3);
   dirty+=doScan(0);
   dirty+=doScan(2);
} /* endwhile */
}

void cThinner::SetCharExtents(){
   int x,y;
PelxMin=xMax; PelyMin=yMax;
PelxMax=PelyMax=0;
for (x=0; x<xMax; x++) {
   for (y=0; y<yMax; y++) {
      if (M[x][y]==1) {
         if(x>PelxMax) PelxMax=x;
         if(y>PelyMax) PelyMax=y;
         if(x<PelxMin) PelxMin=x;
         if(y<PelyMin) PelyMin=y;
         } 
      } /* endfor */
   } /* endfor */
}


int cThinner::WeakCond(int x, int y){
   int i,sum;

sum=0;
if ((x==PelxMax)||(x==PelxMin)) {
   for (i=0; i<=PelyMax; i++) {
      sum+=M[x][i];
      } /* endfor */
   if (sum<2) return 0;
   } /* endif */
sum=0;
if ((y==PelyMax)||(y==PelyMin)) {
   for (i=0; i<=PelyMax; i++) {
      sum+=M[i][y];
      } /* endfor */
   if (sum<2) return 0;
   } /* endif */
return 1;
}

int cThinner::StrongCond(int x, int y){
if ((x>PelxMin) && (x<PelxMax) && (y>PelyMin) &&(y<PelyMax)) 
   return 1;
 else
   return 0;
}

int cThinner::doScanLR(){
  int x1,y1,x2,y2;
  int dirty;
  char c;

dirty=0;
for (x1=1; x1<xMax-1; x1++) {
   x2= xMax-x1; 
   for (y1=1; y1<yMax-1; y1++) {
      if (WeakCond(x1,y1)) {
         if ((ApplyTemplate(x1,y1,3)) || (ApplyTemplate(x1,y1,0))|| (ApplyTemplate(x1,y1,2)))
                dirty=1;
         } /* endif */
      y2=y1;
      if (WeakCond(x2,y2)) {
         if (ApplyTemplate(x2,y2,1))
                dirty=1;
         } /* endif */
      } /* endfor */
   } /* endfor */
return dirty;
}


int cThinner::doScanInOut(){
  int Q1x,Q1y,Q2x,Q2y;
  int Q3x,Q3y,Q4x,Q4y;
  int CenterX1, CenterX2;
  int CenterY1, CenterY2;
  int dirty;
  int done;
  char c;

CenterX1= PelxMin+(PelxMax-PelxMin)/2;
CenterX2= CenterX1+1;
CenterY1= PelyMin+(PelyMax-PelyMin)/2;
CenterY2=CenterY1+1;
Q1x=CenterX2; Q2x=CenterX2; Q3x=CenterX1; Q4x=CenterX1;
Q1y=CenterY2; Q2y=CenterY1; Q3y=CenterY1; Q4y=CenterY2;

dirty=0; done=0;
while (!done) {
   // Apply the templates
   if (WeakCond(Q1x,Q1y) && (Q1x<=PelxMax))
      dirty |= ApplyAllTemplates(Q1x, Q1y);
   if (WeakCond(Q2x,Q2y) && (Q2x<=PelxMax))
      dirty |= ApplyAllTemplates(Q2x, Q2y);
   if (WeakCond(Q3x,Q3y)&& (Q3x>=PelxMin))
      dirty |= ApplyAllTemplates(Q3x, Q3y);
   if (WeakCond(Q4x,Q4y)&& (Q4x>=PelxMin))
      dirty |= ApplyAllTemplates(Q4x, Q4y);
   // Move the templates

   Q1y++;
   if (Q1y>PelyMax) {
      Q1y=CenterY2;
      Q1x++;
      }
   Q2y--;
   if (Q2y<PelxMin) {
      Q2y=CenterY1;
      Q2x++;
      }
   Q3y--;
   if (Q3y<PelyMin) {
      Q3y=CenterY1;
      Q3x--;
      }
   Q4y++;
   if (Q4y>PelyMax) {
      Q4y=CenterY2;
      Q4x--;
      }

   if ((Q1x>PelxMax) && (Q2x>PelxMax) && (Q3x<PelxMin) && (Q4x<PelxMin))
      done=1;
   } /* endwhile */
return dirty;
}

int cThinner::doScan(int Tid){
  int x,y;
  int dirty;

dirty=0;
for (y=1; y<yMax-1; y++) {
   for (x=1; x<xMax-1; x++) {
      if (ApplyTemplate(x,y,Tid))
             dirty=1;
      } /* endfor */
   } /* endfor */
return dirty;
}


int cThinner::ApplyAllTemplates(int x, int y){
int rc;

rc=0;
if (ApplyTemplate(x, y, 1)) rc=1;
if (ApplyTemplate(x, y, 3)) rc=1;
if (ApplyTemplate(x, y, 0)) rc=1;
if (ApplyTemplate(x, y, 2)) rc=1;
return rc;
}

/****************************************************************************
* int cThinner::ApplyTemplate(int x, int y, int Tid)                        *
*                                                                           *
*   Removes center pixel when template is applicable                        *
*                                                                           *
*   x,y locates center of 3x3 template placement                            *
*   Tid is the templates identification                                     *
*****************************************************************************/

int cThinner::ApplyTemplate(int x, int y, int Tid){
  int i,j,sum;

sum=0;
for (j=0; j<3; j++) {
   for (i=0; i<3; i++) {
      M1[i][j] = M[x+i-1][y+j-1];
      sum+=M1[i][j];
   } /* endfor */
} /* endfor */

if(M1[1][1] != 1) return 0;                              // Template mismatch
if (M1[ZeroPosn[Tid].x][ZeroPosn[Tid].y] != 0) return 0; // Template mismatch
if(sum<=2) return 0;  // never delete an isolated pixel
if(sum==8) return 0;  // don't hollow out the core of fat lines
Rotate(Tid);
if (isConnected()) {
   M[x][y]=0;      // Strip the pixel
   return 1;       // DIRTY
   } 
 else {
   return 0;       // NOT DIRTY
   } /* endif */
return 0;
}

void cThinner::Rotate(int Tid){
  int t,i,j,m,n;
  int Temp[3][3];

for (t=0; t<Tid; t++) {
  for (i=0; i<3; i++) {
     for (j=0; j<3; j++) {
       Temp[i][j] = M1[2-j][i];
       } /* endfor */
    } /* endfor */
  for (m=0; m<3; m++) {
     for (n=0; n<3; n++) {
       M1[m][n] = Temp[m][n];
       } /* endfor */
    } /* endfor */
  } /* endfor */
}

void cThinner::buildMap(){
   Map[0].Pel=M1[0][0];
   Map[1].Pel=M1[0][1];
   Map[2].Pel=M1[0][2];
   Map[3].Pel=M1[1][2];
   Map[4].Pel=M1[2][2];
   Map[5].Pel=M1[2][1];
   Map[6].Pel=M1[2][0];
}

int cThinner::isPath(int i, int j) {
  int k;

k=Map[i].Next1;
while ((k<j) && (k>-1)) {
   if (Map[k].Pel) {
      if (Map[k].Next1==j) return 1;
      if (Map[k].Next2==j) return 1;
      k=Map[k].Next1;
      }
    else {
      return 0;
      } /* endif */
   } /* endwhile */
printf("ERROR:Problem in isPath");
return 1;
}


int cThinner::isConnected(){
  int i,j,rc;

rc=1;
buildMap();
for (i=0; i<=4; i+=2) {
   for (j=i+2; j<=6; j++) {
      if ((Map[i].Pel==1) && (Map[j].Pel==1)) {
         if (!isPath(i,j)) rc=0;
         } 
       else {
         } /* endif */
      } /* endfor */
   } /* endfor */
for (i=1; i<=3; i+=2) {
   for (j=i+3; j<=6; j++) {
      if ((Map[i].Pel==1) && (Map[j].Pel==1)) {
         if (!isPath(i,j)) rc=0;
         } 
       else {
         } /* endif */
      } /* endfor */
   } /* endfor */
return rc;
}

void cThinner::ShowMap(){
   int i;
printf("\n[");
for (i=0; i<=6; i++) {
   printf("%d",Map[i].Pel);
   } /* endfor */
printf("]\n");
}

void cThinner::Show2(FILE *Ofile){
   int i,j;
   char s1[80]; 
   char s2[80];
printf("\n");
for (j=0; j<yMax; j++) {
   strcpy(s1," ");
   strcpy(s2,"    ");
   for (i=0; i<xMax; i++) {
      if (Stage1[i][yMax-j-1])
         strcat(s1,"X");
       else
         strcat(s1,".");
      if (M[i][yMax-j-1])
         strcat(s2,"X");
       else
         strcat(s2,".");
      } /* endfor */
   printf("%s%s\n",s1,s2);
   fprintf(Ofile,"%s%s\n",s1,s2);
   } /* endfor */
printf("\n");
}


void cThinner::ShowM(){
   int i,j;
printf("\n");
for (j=0; j<yMax; j++) {
   for (i=0; i<xMax; i++) {
      if (M[i][yMax-j-1])
         printf("X");
       else
         printf(".");
      } /* endfor */
   printf("\n");
   } /* endfor */
printf("\n");
}

void cThinner::ShowW(){
   int i,j;
printf("\n");
for (j=0; j<yMax; j++) {
   for (i=0; i<xMax; i++) {
      if (W[i][yMax-j-1])
         printf("X");
       else
         printf(".");
      } /* endfor */
   printf("\n");
   } /* endfor */
printf("\n");
}


void    cThinner::ShowLoops(FILE *Ofile){
   int i,j;
printf("\n");
fprintf(Ofile,"\n");
for (j=0; j<yMax; j++) {
   for (i=0; i<xMax; i++) {
      if (Stage2[i][yMax-j-1]){
         printf("X");
         fprintf(Ofile,"X");
         }
       else {
         printf(".");
         fprintf(Ofile,".");
         }
      } /* endfor */
   printf("\n");
   fprintf(Ofile,"\n");
   } /* endfor */
printf("\n");
}

void cThinner::fShowM(FILE *Ofile){
   int i,j;
fprintf(Ofile,"\n");
for (j=0; j<yMax; j++) {
   for (i=0; i<xMax; i++) {
      if (M[i][yMax-j-1])
         fprintf(Ofile,"X");
       else
         fprintf(Ofile,".");
      } /* endfor */
   fprintf(Ofile,"\n");
   } /* endfor */
fprintf(Ofile,"\n");
}

void cThinner::ShowM1(){
   int i,j;
printf("\n");
for (j=0; j<3; j++) {
   for (i=0; i<3; i++) {
      if (M1[i][2-j])
         printf("X");
       else
         printf(".");
      } /* endfor */
   printf("\n");
   } /* endfor */
printf("\n");
}

int cThinner::isEndPt(int x, int y) {
  int sum,i,j;
sum=-1;     //account for centrer pixel being on
for (j=y-1; j<=y+1; j++) {
   for (i=x-1; i<=x+1; i++) {
      if((i>=0) && (j>=0) &&(i<xMax) && (j<yMax))
         sum+=M[i][j];   // count the neighbors
      } /* endfor */
   } /* endfor */
if (sum==1) {         // Exactly one neighbor on
   return 1;          // defines an enpoint.
   }/* endif */
return 0;
}

int cThinner::isIntersect(int x, int y) {
  int sum,i,j;
sum=-1;     //account for centrer pixel being on 
for (j=y-1; j<=y+1; j++) {
   for (i=x-1; i<=x+1; i++) {
      if((i>=0) && (j>=0) && (i<xMax) && (j<yMax))
         sum+=M[i][j];   // count the neighbors
      } /* endfor */
   } /* endfor */
if (sum>=3) {         // three or more neighbors 'ON'
   return 1;          // defines an intersection.
   }/* endif */
return 0;
}


void cThinner::LocateLoops() {
   int x,y,m;
LoopCnt=0;
Grid2Work();              //SAVE COPY OF ORIG
while (QueryEndCount()>0){
   LocateEndPts();
   LocateIntersects();
   KillEndPaths();
   Thin2();
   }
IsolatedPelcleanup();
Grid2Stage2();        //Archive the isolated loops
if (!isAnyPelOn()) {
   //No L00PS DETECTED
   LoopCnt=0;
   }
 else {
   Frame2Ones();
   if (QueryIntCount()==0) {
       //There is exactly 1 loop
       LoopCnt=1;
       isAnyPelOff(x,y);
       // dont need to do the next 3 statements if only concerned
       // with the number of loops
       KillOneLoop(x,y,m);// kill the pel and all its friends
       LoopLocation[0].x=x;
       LoopLocation[0].y=y;
       LoopLocation[0].m=m;
       }
     else {
       //There are multiple loops
       LoopCnt=0;
       while (isAnyPelOff(x,y)) {
          KillOneLoop(x,y,m);// kill the pel and all its friends
          LoopLocation[LoopCnt].x=x;
          LoopLocation[LoopCnt].y=y;
          LoopLocation[LoopCnt].m=m;
          LoopCnt++;
          } /* endwhile */
       } /* endif */
   } /* endif */
Work2Grid();          //RESTORE ORIG GRID
LocateEndPts();       //Played with these sooo...
LocateIntersects();   // ...they need restoration too

}


void cThinner::LocateEndPts() {
   int x,y,i,j;
EndPtCnt=0;
for (y=0; y<yMax; y++) {
   for (x=0; x<xMax; x++) {
      if ((M[x][y]==1) && isEndPt(x,y)) {
         // we have an endpoint so do something with it.
         EndPoint[EndPtCnt].x=x;
         EndPoint[EndPtCnt].y=y;
         EndPtCnt++;
      } else {
      } /* endif */
   } /* endfor */
} /* endfor */
}

int  cThinner::isIntersect2(int x, int y){
int found,i;
found=0;
for (i=0; i<IntPtCnt; i++) {
   if ( (IntersectPoint[i].x==x) && (IntersectPoint[i].y==y))
      found=1;
   } /* endfor */
return found;
}

void cThinner::LocateIntersects() {
   int x,y,i,j;
IntPtCnt=0;
for (y=0; y<yMax; y++) {
   for (x=0; x<xMax; x++) {
      if ((M[x][y]==1) && isIntersect(x,y)) {
         // we have an intersection point so do something with it.
         IntersectPoint[IntPtCnt].x=x;
         IntersectPoint[IntPtCnt].y=y;
         IntPtCnt++;
         } 
       else {
         } /* endif */
      } /* endfor */
   } /* endfor */
}

tgrid   cThinner::QueryEndPoint(int n){
   tgrid RetVal;
RetVal.x= EndPoint[n].x;
RetVal.y= EndPoint[n].y;
return RetVal;
}

tgrid   cThinner::QueryIntPoint(int n){
   tgrid RetVal;
RetVal.x= IntersectPoint[n].x;
RetVal.y= IntersectPoint[n].y;
return RetVal;
}

void cThinner::Frame2Ones(){
   coordq f21;
   tgrid  fpoint;
   int x,y;
fpoint.x =0;
fpoint.y =0;
NQZeroes(&f21,fpoint);
while (f21.DatAvail()) {
   f21.deQTop(x, y);
   M[x][y]=1;
   } /* endwhile */
}

int cThinner::ValidZeroChild(int cx, int cy, int px, int py){
if ((cx<0) || (cy<0) || (cx>17) || (cy>25)) // stay on grid
            return 0;
if (M[cx][cy]!=0)                     // Pel must be zero
            return 0;
if ((cx==px) || cy==py)               // no x-ings possible for
            return 1;                 // directly hor/vert neighbor
if ((M[cx][py]==1) && (M[px][cy]==1)) // Check diagonal neighors
            return 0;
return 1;
}

void cThinner::NQZeroes(coordq *targQ, tgrid seedpel){
   coordq open;
   int x,y,i,j;
if (M[seedpel.x][seedpel.y]==0) open.enQTop(seedpel);
        else return ; //exit if seed nonzero
while (open.DatAvail()) {
   open.deQTop(x, y);
   targQ->enQTop(x,y);
   // Now examine each NN of pel at (x,y) ...
   // ...if its valid & not already present we'll
   // place it on open.
   for (j=-1; j<=1; j++) {
      for (i=-1; i<=1; i++) {
         if (!((i==0) && (j==0)) ) {
            //each NN visited here
            if(ValidZeroChild(x-i,y-j,x,y)){
               if ((open.find(x-i,y-j)==0) && (targQ->find(x-i,y-j)==0)){
                  open.enQTop(x-i,y-j);
                  }
               }
            } /* endif */
      } /* endfor */
   } /* endfor */
   } /* endwhile */
}

void cThinner::KillOneLoop(int& x, int& y, int& m) {
    coordq targQ;
    tgrid  seedpel;
    int sx,sy;
m=0;
seedpel.x=x;
seedpel.y=y;
sx=sy=0;
NQZeroes(&targQ, seedpel); //all interior loop-pels to targq
while (targQ.DatAvail()) { //while they last
   targQ.deQTop(x, y);     //examine them 1 by 1
   sx+=x;                  // to determine loop
   sy+=y;                  //   coords  and
   m++;                    //     mass
   M[x][y]=1;              // and delete
   } /* endwhile */
if (m>0){
   x=sx/m;
   y=sy/m;}
 else {
    printf("\nERROR: LOOP HAS ZERO MASS!");
    }
}

cThinner        Thinner;
cRawData        idata;

int main(int argc, char *argv[])
{
  int           mx,my,i,j,d,chIndx;
  char inname[80];
  char outname[80];
  char outext[80], *poutext;
  FILE *OutData;
  tgrid fpt;
  int fcnt;

mx=18; my=26;
strcpy(inname,argv[1]);
strcat(inname,".bm");
if (!idata.Open(inname)) return -1; // initialize
for (chIndx=0; chIndx<10; chIndx++) {
   if(idata.Read(chIndx)==0) return 0;
   strcpy(outname,argv[1]);
   strcat(outname,".");
   poutext=itoa(chIndx,outext,10);
   strcat(outname,outext);
   if((OutData=fopen(outname,"w"))==0) {
      printf("Outfile open failed");
      return 0;
      }
   printf("\n\n==========  %s  ========== \n",outname);
   Thinner.SetGridSize(mx, my);
   for (j=0; j<my; j++) {
      for (i=0; i<mx; i++) {
         if((i>0) && (j>0) && (i<mx-1) && (j<my-1) )
            d=idata.QueryXY(i-1,j-1);
          else
            d=0;
         Thinner.Store(i,j,d);
      } /* endfor */
   } /* endfor */

   Thinner.SetCharExtents();
   Thinner.Thin1();
   Thinner.Thin2();
   Thinner.LocateEndPts();
   Thinner.LocateIntersects();
   Thinner.KillStubs();

   // SHOW IT
   Thinner.Show2(OutData);

   Thinner.LocateLoops();
   if(Thinner.QueryLoopCnt())
       Thinner.ShowLoops(OutData);


   fcnt=  Thinner.QueryEndCount();
   printf("\n   End Points:");
   fprintf(OutData,"End Points:");
   for (i=0; i<fcnt; i++) {
      fpt=   Thinner.QueryEndPoint(i);
      printf("[%d,%d]", fpt.x,fpt.y);
      fprintf(OutData,"[%d,%d]", fpt.x,fpt.y);
      } /* endfor */

   printf("\n   Intersects:");
   fprintf(OutData,"\nIntersects:");
   fcnt=  Thinner.QueryIntCount();
   for (i=0; i<fcnt; i++) {
     fpt =  Thinner.QueryIntPoint(i);
     printf("[%d,%d]", fpt.x,fpt.y);
     fprintf(OutData,"[%d,%d]", fpt.x,fpt.y);
     } /* endfor */
   printf("\n");
   fprintf(OutData,"\n");

   int Lcnt;
   tLoop Lpt;
   Lcnt=Thinner.QueryLoopCnt();
   if (Lcnt==0) {
      printf("\nNo loops detected.");
      fprintf(OutData,"\nLoops:     ");
   } else {
      printf("\n   Loops:     ");
      fprintf(OutData,"\nLoops:     ");
      for (i=0; i<Lcnt; i++) {
        Lpt =  Thinner.QueryLoop(i);
        printf("[m=%d,(%d,%d)]", Lpt.m,Lpt.x,Lpt.y);
        fprintf(OutData,"[m=%d,(%d,%d)]", Lpt.m, Lpt.x,Lpt.y);
        } /* endfor */
      printf("\n");
      fprintf(OutData,"\n");
   } /* endif */


   fclose(OutData);
   } /* endfor */

return 0;
}

