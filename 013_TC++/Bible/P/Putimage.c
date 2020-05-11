
/*                          */
/* Program Name: putimage.c */
/*                          */
#include <stdio.h>
#include <alloc.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   char far *image_buffer;
   unsigned bar_bytes;
   initgraph(&gdrive,&graphmode,"");
   setcolor(BLUE);
   bar(0,0,50,50);
   bar_bytes=imagesize(0,0,50,50);
   image_buffer=(char far *) malloc(bar_bytes);
   getimage(0,0,50,50,image_buffer);
   outtextxy(getmaxx()/2-116,getmaxy()-16,"Press any key to"
                                          " copy this bar");
   getch();
   putimage(getmaxx()-50,getmaxy()-50,image_buffer,COPY_PUT)
   ;
   outtextxy(getmaxx()/2-84,getmaxy()-8,"Press any key to"
                                                  " exit");
   getch();
   closegraph();
}
