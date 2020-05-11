
/*                        */
/* Program Name: clreol.c */
/*                        */
#include <conio.h>

void main(void)
{
   clrscr();
   gotoxy(35,13);
   cputs("Hi! Borland");
   gotoxy(28,24);
   cputs("Press any key to erase name");
   getch();
   gotoxy(38,13);
   clreol();
   gotoxy(31,25);
   cputs("Press any key to exit");
   getch();
}
