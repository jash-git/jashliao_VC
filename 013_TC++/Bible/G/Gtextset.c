/*                          */
/* Program Name: gtextset.c */
/*                          */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

/* The names of the supported fonts */
char *font[]={"DEFAULT_FONT","TRIPLEX_FONT","SMALL_FONT",
              "SANS_SERIF_FONT","GOTHIC_FONT"};

/* The names of the text directions supported */
char *direction[]={"HORIZ_DIRECTION","VERT_DIRECTION"};

/* Horizontal text justifications supported */
char *hjust[]={"LEFT_TEXT","CENTER_TEXT","RIGHT_TEXT"};

/* Vertical text justifications supported */
char *vjust[]={"BOTTOM_TEXT","CENTER_TEXT","TOP_TEXT"};

void main(void)
{
   int gdrive=DETECT,graphmode;
   int midx,midy;
   struct textsettingstype textinfo;
   char fontstr[80],directionstr[80],charsizestr[80],
        hjuststr[80],vjuststr[80];
   initgraph(&gdrive,&graphmode,"");
   midx=getmaxx()/2;
   midy=getmaxy()/2;
   gettextsettings(&textinfo);
   sprintf(fontstr,"%s is the text style.",
                       font[textinfo.font]);
   sprintf(directionstr,"%s is the direction.",
                 direction[textinfo.direction]);
   sprintf(charsizestr,"%d is the text size.",
                            textinfo.charsize);
   sprintf(hjuststr,"%s is the horizontal justification.",
                                    hjust[textinfo.horiz]);
   sprintf(vjuststr,"%s is the vertical justification.",
                                     vjust[textinfo.vert]);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   outtextxy(midx,midy,fontstr);
   outtextxy(midx,midy+2*8,directionstr);
   outtextxy(midx,midy+4*8,charsizestr);
   outtextxy(midx,midy+6*8,hjuststr);
   outtextxy(midx,midy+8*8,vjuststr);
   outtextxy(midx,getmaxy()-8,"Press any key to"
                                        " exit");
   getch();
   closegraph();
}
