
/*                          */
/* Program Name: fillpoly.c */
/*                          */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int numpoints=6,polypoints[12]={50,50,70,70,60,80,40,80,
                                               30,70,50,50};
   initgraph(&gdrive,&graphmode,"");
   setlinestyle(0,0x3ff,1);
   setfillstyle(1,BLUE);
   fillpoly(numpoints,polypoints);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to exit");
   getch();
   closegraph();
}
