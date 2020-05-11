
/*                     */
/* Program Name: bar.c */
/*                     */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int left,top,right,bottom;
   printf("Enter parameter about drawing an bar graph\n");
   printf("Coordinates of upper left corner(left, top): ");
   scanf("%d %d",&left,&top);
   printf("Coordinates of lower right corner"
                        " (right, bottom): ");
   scanf("%d %d",&right,&bottom);
   initgraph(&gdrive,&graphmode,"");
   setfillstyle(1,BLUE);
   bar(left,top,right,bottom);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
