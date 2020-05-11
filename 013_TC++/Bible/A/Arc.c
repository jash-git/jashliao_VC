
/*                     */
/* Program Name: arc.c */
/*                     */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int x,y,radius,stangle,endangle;
   printf("Enter parameter about drawing an arc\n");
   printf("Coordinates of center(x,y): ");
   scanf("%d %d",&x,&y);
   printf("Radius: ");
   scanf("%d",&radius);
   printf("Start angle: ");
   scanf("%d",&stangle);
   printf("End angle: ");
   scanf("%d",&endangle);
   initgraph(&gdrive,&graphmode,"");
   setlinestyle(0,0x3ff,THICK_WIDTH);
   arc(x,y,stangle,endangle,radius);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
