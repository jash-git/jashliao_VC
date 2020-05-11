
/*                          */
/* Program Name: textheig.c */
/*                          */
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void main(void)
{
   char msg[80];
   int i,y=0;
   int gdrive=DETECT,graphmode;
   initgraph(&gdrive,&graphmode,"");
   for (i=1;i<9;i++) {
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,i);
      sprintf(msg,"Size: %d",i);
      outtextxy(1,y,msg);
      y+=textheight(msg);
   }
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(getmaxx()/2,getmaxy()-7,"Press any key to exit");
   getch();
   closegraph();
}
