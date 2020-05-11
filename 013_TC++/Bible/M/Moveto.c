
/*                        */
/* Program Name: moveto.c */
/*                        */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int x,y;
   printf("Enter new points(x, y) to change"
                  " CP(current position)\n");
   printf("New point(x, y): ");
   scanf("%d %d",&x,&y);
   initgraph(&gdrive,&graphmode,"");
   putpixel(getx(),gety(),BLUE);
   outtextxy(getx()+4,gety()+4,"Old CP(current position)");
   moveto(x,y);
   putpixel(getx(),gety(),BLUE);
   outtextxy(getx()+4,gety()+4,"New CP(current position)");
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
