
/*                      */
/* Program Name: line.c */
/*                      */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int x1,y1,x2,y2;
   printf("Enter two points(x, y) to draw a line\n");
   printf("First point(x, y): ");
   scanf("%d %d",&x1,&y1);
   printf("Second point(x, y): ");
   scanf("%d %d",&x2,&y2);
   initgraph(&gdrive,&graphmode,"");
   setcolor(BLUE);
   setlinestyle(0,0x3ff,1);
   line(x1,y1,x2,y2);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
