
/*                          */
/* Program Name: cldevice.c */
/*                          */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   initgraph(&gdrive,&graphmode,"");
   setlinestyle(0,0x3ff,1);
   circle(359,173,100);
   outtextxy(getmaxx()/2-116,getmaxy()-8,"Press any key to"
                                           " clear screen");
   getch();
   setbkcolor(BLUE);
   cleardevice();
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
