
/*                         */
/* Program Name: linerel.c */
/*                         */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int xd,yd;
   printf("Enter x-offset and y-offset to draw a line\n");
   printf("x-offset: ");
   scanf("%d",&xd);
   printf("y-offset: ");
   scanf("%d",&yd);
   initgraph(&gdrive,&graphmode,"");
   setcolor(BLUE);
   setlinestyle(0,0x3ff,1);
   linerel(xd,yd);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
