
/*                          */
/* Program Name: regiffon.c */
/*                          */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(void)
{
   int gdrive=DETECT,graphmode;
   int errorcode1=0,errorcode2=0;
   int midx,midy;
   errorcode1=registerbgifont(triplex_font);
   errorcode2=registerfarbgifont(sansserif_font_far);
   initgraph(&gdrive,&graphmode,"");
   midx=getmaxx()/2;
   midy=getmaxy()/2;
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(midx,midy,"The TRIPLEX FONT");
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   outtextxy(midx,midy+16,"The SANSSERIF FONT");
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(midx,getmaxy()-8,"Press any key to"
                                        " exit");
   getch();
   closegraph();
}
