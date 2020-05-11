
/*                         */
/* Program Name: outtext.c */
/*                         */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int midx,midy;
   initgraph(&gdrive,&graphmode,"");
   midx=getmaxx()/2;
   midy=getmaxy()/2;
   moveto(midx,midy);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtext("This is a test.");
   outtextxy(midx,getmaxy()-16,"Press any key to"
                                        " exit");
   getch();
   closegraph();
}
