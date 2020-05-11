
/*                        */
/* Program Name: lineto.c */
/*                        */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int x,y;
   printf("Enter new points(x, y) to draw a line\n");
   printf("New point(x, y): ");
   scanf("%d %d",&x,&y);
   initgraph(&gdrive,&graphmode,"");
   setcolor(BLUE);
   setlinestyle(0,0x3ff,1);
   lineto(x,y);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
