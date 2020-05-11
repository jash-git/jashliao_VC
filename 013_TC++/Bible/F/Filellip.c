
/*                          */
/* Program Name: filellip.c */
/*                          */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int x,y,xradius,yradius;
   printf("Enter parameter about drawing an ellipse\n");
   printf("Coordinates of center(x,y): ");
   scanf("%d %d",&x,&y);
   printf("Horizontal axes: ");
   scanf("%d",&xradius);
   printf("Vertical axes: ");
   scanf("%d",&yradius);
   initgraph(&gdrive,&graphmode,"");
   setfillstyle(1,BLUE);
   fillellipse(x,y,xradius,yradius);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
