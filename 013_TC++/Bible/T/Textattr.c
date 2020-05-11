
/*                          */
/* Program Name: textattr.c */
/*                          */
#include <conio.h>

void main(void)
{
   int i,j;
   clrscr();
   for (i=1,j=8;i<=7;i++,j++) {
      textattr(j+(i<<4));
      cprintf("This is a test of text attribute\r\n");
   }
}
