
/*                          */
/* Program Name: gettinfo.c */
/*                          */
#include <conio.h>
#include <stdio.h>

void main(void)
{
   struct text_info ti;
   clrscr();
   gettextinfo(&ti);
   printf("window left      %2d\n",ti.winleft);
   printf("window top       %2d\n",ti.wintop);
   printf("window right     %2d\n",ti.winright);
   printf("window bottom    %2d\n",ti.winbottom);
   printf("attribute        %2d\n",ti.attribute);
   printf("normal attribute %2d\n",ti.normattr);
   printf("current mode     %2d\n",ti.currmode);
   printf("screen height    %2d\n",ti.screenheight);
   printf("screen width     %2d\n",ti.screenwidth);
   printf("current x        %2d\n",ti.curx);
   printf("current y        %2d\n",ti.cury);
}
