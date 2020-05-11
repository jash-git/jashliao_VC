
/*                        */
/* Program Name: clrscr.c */
/*                        */
#include <conio.h>

void main(void)
{
   clrscr();
   gotoxy(35,13);
   cputs("Hi! Borland");
   gotoxy(28,25);
   cputs("Press any key to clear screen");
   getch();
   clrscr();
   gotoxy(28,24);
   cputs("The screen has been cleared");
   gotoxy(31,25);
   cputs("Press any key to exit");
   getch();
}
