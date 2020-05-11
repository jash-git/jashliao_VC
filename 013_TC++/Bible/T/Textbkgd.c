
/*                          */
/* Program Name: textbkgd.c */
/*                          */
#include <conio.h>

void main(void)
{
   int i;
   clrscr();
   for (i=0;i<=7;i++) {
      textbackground(i);
      cprintf("This is a test of textbackground color\r\n");
   }
   getch();
}
