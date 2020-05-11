
/*                         */
/* Program Name: moverel.c */
/*                         */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int xd,yd;
   printf("Enter x-offset and y-offset to change"
                       " CP(current position)\n");
   printf("x-offset: ");
   scanf("%d",&xd);
   printf("y-offset: ");
   scanf("%d",&yd);
   initgraph(&gdrive,&graphmode,"");
   putpixel(getx(),gety(),BLUE);
   outtextxy(getx()+4,gety()+4,"Old CP(current position)");
   moverel(xd,yd);
   putpixel(getx(),gety(),BLUE);
   outtextxy(getx()+4,gety()+4,"New CP(current position)");
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
