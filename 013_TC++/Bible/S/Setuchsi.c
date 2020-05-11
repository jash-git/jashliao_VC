
/*                           */
/* Program Name : setuchsi.c */
/*                           */

#include <graphics.h>
#include <conio.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   initgraph(&gdrive,&graphmode,"");
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
   moveto(0,getmaxy()/2);
   outtext("Norm ");
   setusercharsize(1,3,1,1);
   outtext("Short ");
   setusercharsize(3,1,1,1);
   outtext("Wide ");
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(getmaxx()/2,getmaxy()-7,"Press any key to exit");
   getch();
   closegraph();
}
