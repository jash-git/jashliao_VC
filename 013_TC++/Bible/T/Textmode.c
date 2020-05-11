
/*                          */
/* Program Name: textmode.c */
/*                          */
#include <conio.h>

void main(void)
{
   clrscr();
   textmode(BW40);
   cprintf("This is a test of text mode\r\n");
   textmode(C40);
   cprintf("This is a test of text mode\r\n");
   textmode(BW80);
   cprintf("This is a test of text mode\r\n");
   textmode(C80);
   cprintf("This is a test of text mode\r\n");
   textmode(MONO);
   cprintf("This is a test of text mode\r\n");
   getch();
}
