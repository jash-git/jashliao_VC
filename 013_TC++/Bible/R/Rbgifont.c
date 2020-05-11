
/*                          */
/* Program Name: rbgifont.c */
/*                          */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int errorcode;
   int midx,midy;
   errorcode=registerbgifont(triplex_font);
   initgraph(&gdrive,&graphmode,"");
   midx=getmaxx()/2;
   midy=getmaxy()/2;
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(midx,midy,"The TRIPLEX FONT");
   outtextxy(midx,getmaxy()-16,"Press any key to"
                                        " exit");
   getch();
   closegraph();
}
