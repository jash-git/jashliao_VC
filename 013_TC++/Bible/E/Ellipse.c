
/*                         */
/* Program Name: ellipse.c */
/*                         */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int x,y,xradius,yradius,stangle,endangle;
   printf("Enter parameter about drawing an ellipse\n");
   printf("Coordinates of center(x,y): ");
   scanf("%d %d",&x,&y);
   printf("Horizontal axes: ");
   scanf("%d",&xradius);
   printf("Vertical axes: ");
   scanf("%d",&yradius);
   printf("Start angle: ");
   scanf("%d",&stangle);
   printf("End angle: ");
   scanf("%d",&endangle);
   initgraph(&gdrive,&graphmode,"");
   setlinestyle(0,0x3ff,THICK_WIDTH);
   ellipse(x,y,stangle,endangle,xradius,yradius);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
