
/*                        */
/* Program Name: circle.c */
/*                        */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int x,y,radius;
   printf("Enter parameter about drawing a circle\n");
   printf("Coordinates of center(x,y): ");
   scanf("%d %d",&x,&y);
   printf("Radius: ");
   scanf("%d",&radius);
   initgraph(&gdrive,&graphmode,"");
   setlinestyle(0,0x3ff,1);
   circle(x,y,radius);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
						  " exit");
   getch();
   closegraph();
}
