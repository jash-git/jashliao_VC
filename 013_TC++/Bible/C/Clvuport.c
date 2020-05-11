
/*                          */
/* Program Name: clvuport.c */
/*                          */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   initgraph(&gdrive,&graphmode,"");
   outtextxy(getmaxx()/2-116,getmaxy()-8,"Press any key to"
                                         " clear viewport");
   setlinestyle(0,0x3ff,1);
   setviewport(50,50,250,250,1);
   circle(25,25,20);
   getch();
   clearviewport();
   outtextxy(0,0,"Press any key to exit");
   getch();
   closegraph();
}
