
/*                          */
/* Program Name: putpixel.c */
/*                          */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int i,j;
   initgraph(&gdrive,&graphmode,"");
   setcolor(WHITE);
   bar(0,0,50,50);
   outtextxy(getmaxx()/2-164,getmaxy()-16,"Press any key to"
                                " change color of this bar");
   getch();
   for (i=0;i<=getmaxx();i++) {
      for (j=0;j<=getmaxy();j++) {
         if (getpixel(i,j)==WHITE) {
            putpixel(i,j,BLUE);
         }
      }
   }
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
