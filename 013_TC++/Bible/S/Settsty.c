
/*                          */
/* Program Name : settsty.c */
/*                          */

#include <graphics.h>
#include <conio.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int th,i;
   initgraph(&gdrive,&graphmode,"");
   for (i=1;i<=6;i++) {
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,i);
      settextjustify(CENTER_TEXT,CENTER_TEXT);
      th=textheight("A");
      moveto(getmaxx()/4,gety()+th);
      outtext("This is a test.");
   }
   moveto(getmaxx()/2,getmaxy()/2);
   for (i=1;i<=6;i++) {
      settextstyle(SANS_SERIF_FONT,VERT_DIR,i);
      settextjustify(CENTER_TEXT,CENTER_TEXT);
      th=textheight("A");
      moveto(getx()+th,gety());
      outtext("This is a test.");
   }
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(getmaxx()/2,getmaxy()-7,"Press any key to exit");
   getch();
   closegraph();
}
