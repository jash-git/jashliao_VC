
/*                         */
/* Program Name: insline.c */
/*                         */
#include <conio.h>

void main(void)
{
   clrscr();
   gotoxy(35,13);
   cputs("Hi! Borland");
   gotoxy(35,14);
   cputs("How do you do?");
   gotoxy(3,25);
   cputs("Press any key to insert one line between first"
                         " sentence and second sentence");
   getch();
   gotoxy(35,14);
   insline();
   gotoxy(31,25);
   cputs("Press any key to exit");
   getch();
}
