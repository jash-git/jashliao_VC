
/*                          */
/* Program Name: floodfil.c */
/*                          */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   initgraph(&gdrive,&graphmode,"");
   setcolor(WHITE);
   setlinestyle(0,0x3ff,1);
   ellipse(359,173,0,360,100,50);
   setfillstyle(1,BLUE);
   floodfill(359,173,WHITE);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
