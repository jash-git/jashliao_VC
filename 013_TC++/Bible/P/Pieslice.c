
/*                          */
/* Program Name: pieslice.c */
/*                          */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int x,y,radius,stang,endang;
   printf("Enter parameter about drawing an pieslice\n");
   printf("Coordinates of center(x,y): ");
   scanf("%d %d",&x,&y);
   printf("Radius: ");
   scanf("%d",&radius);
   printf("Start angle: ");
   scanf("%d",&stang);
   printf("End angle: ");
   scanf("%d",&endang);
   initgraph(&gdrive,&graphmode,"");
   setcolor(BLUE);
   pieslice(x,y,stang,endang,radius);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
