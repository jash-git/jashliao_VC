
/*                         */
/* Program Name: delline.c */
/*                         */
#include <conio.h>

void main(void)
{
   clrscr();
   gotoxy(35,13);
   cputs("Hi! Borland");
   gotoxy(35,14);
   cputs("How are you?");
   gotoxy(35,15);
   cputs("How do you do?");
   gotoxy(22,24);
   cputs("Press any key to erase second sentence");
   getch();
   gotoxy(35,14);
   delline();
   gotoxy(26,24);
   cputs("Second sentence has been erased");
   gotoxy(31,25);
   cputs("Press any key to exit");
   getch();
}
