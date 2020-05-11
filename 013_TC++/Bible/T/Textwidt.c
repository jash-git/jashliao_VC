
/*                          */
/* Program Name: textwidt.c */
/*                          */
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void main(void)
{
   char msg[80];
   int i,x=0;
   int gdrive=DETECT,graphmode;
   initgraph(&gdrive,&graphmode,"");
   for (i=1;i<8;i++) {
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,i);
      sprintf(msg,"Size: %d",i);
      outtextxy(x,getmaxy()/2,msg);
      x+=textwidth(msg);
   }
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(getmaxx()/2,getmaxy()-7,"Press any key to exit");
   getch();
   closegraph();
}
