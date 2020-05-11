
/*                        */
/* Program Name : bar3d.c */
/*                        */

#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int left,top,right,bottom;
   int depth,topflag;
   printf("Enter parameter about drawing a 3d rectangular"
                                                 " bar\n");
   printf("Coordinates of upper left corner (left, top): ");
   scanf("%d %d",&left,&top);
   printf("Coordinates of lower right corner"
                        " (right, bottom): ");
   scanf("%d %d",&right,&bottom);
   printf("Depth: ");
   scanf("%d",&depth);
   printf("Put on the top(Y/N): ");
   topflag=getche();
   if (topflag=='y' || topflag=='Y')
      topflag=1;
   else
      topflag=0;
   initgraph(&gdrive,&graphmode,"");
   setfillstyle(1,YELLOW);
   bar3d(left,top,right,bottom,depth,topflag);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
