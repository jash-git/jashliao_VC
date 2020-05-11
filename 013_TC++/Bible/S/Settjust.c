
/*                           */
/* Program Name : settjust.c */
/*                           */

#include <graphics.h>
#include <conio.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int midx,midy,tw,th;
   initgraph(&gdrive,&graphmode,"");
   midx=getmaxx()/2;
   midy=getmaxy()/2;
   line(midx-150,midy,midx+150,midy);
   line(midx,midy-150,midx,midy+150);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,16);
   tw=textwidth("B");
   th=textheight("B");
   settextjustify(LEFT_TEXT,TOP_TEXT);
   outtextxy(midx,midy,"B");
   settextjustify(LEFT_TEXT,BOTTOM_TEXT);
   outtextxy(midx,midy,"B");
   settextjustify(RIGHT_TEXT,TOP_TEXT);
   outtextxy(midx,midy,"B");
   settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
   outtextxy(midx,midy,"B");
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   settextjustify(LEFT_TEXT,BOTTOM_TEXT);
   moveto(midx+tw+30,midy-th-30);
   outtext("LEFT_TEXT,BOTTOM_TEXT");
   moveto(midx+tw+30,midy+th+30);
   settextjustify(LEFT_TEXT,TOP_TEXT);
   outtext("LEFT_TEXT,TOP_TEXT");
   moveto(midx-tw-30,midy+th+30);
   settextjustify(RIGHT_TEXT,TOP_TEXT);
   outtext("RIGHT_TEXT,TOP_TEXT");
   moveto(midx-tw-30,midy-th-30);
   settextjustify(RIGHT_TEXT,BOTTOM_TEXT);
   outtext("RIGHT_TEXT,BOTTOM_TEXT");
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(midx,getmaxy()-7,"Press any key to exit");
   getch();
   closegraph();
}
