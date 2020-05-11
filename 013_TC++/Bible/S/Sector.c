
/*                         */
/* Program Name : sector.c */
/*                         */

#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int x,y,xradius,yradius,stang,endang;
   printf("Enter parameter about drawing an sector\n");
   printf("Coordinates of center(x,y): ");
   scanf("%d %d",&x,&y);
   printf("Xradius: ");
   scanf("%d",&xradius);
   printf("Yradius: ");
   scanf("%d",&yradius);
   printf("Start angle: ");
   scanf("%d",&stang);
   printf("End angle: ");
   scanf("%d",&endang);
   initgraph(&gdrive,&graphmode,"");
   setcolor(BLUE);
   sector(x,y,stang,endang,xradius,yradius);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
