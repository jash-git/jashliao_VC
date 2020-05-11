
/*                          */
/* Program Name: textcolo.c */
/*                          */
#include <conio.h>

void main(void)
{
   int i,j;
   clrscr();
   for (i=0;i<=15;i++) {
      textcolor(i);
      cprintf("This is a test of textforeground color\r\n");
   }
   getch();
}
