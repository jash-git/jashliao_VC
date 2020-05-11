
/*                                */
/*    Program Name: imagesiz.c    */
/*                                */
#include <stdio.h>
#include <alloc.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   char buffer[80];
   unsigned bar_bytes;
   initgraph(&gdrive,&graphmode,"");
   setcolor(BLUE);
   bar(0,0,50,50);
   bar_bytes=imagesize(0,0,50,50);
   sprintf(buffer,"To save image of this 50*50 bar,"
                      " we need %u bytes",bar_bytes);
   outtextxy(getmaxx()/2-197,getmaxy()-16,buffer);
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
