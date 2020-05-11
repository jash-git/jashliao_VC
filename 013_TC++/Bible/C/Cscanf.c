/*                         */
/* Program Name : cscanf.c */
/*                         */

#include <conio.h>

void main()
{
   char msg[81];

   clrscr();
   cprintf("Please enter a message: ");
   cscanf("%s", msg);

   getch(); /* absorb the '\n' in keyboard buffer */

   cprintf("\r\nThe message you entered is : %s", msg);

   cprintf("\r\n\r\nPress any key to continue...");
   getch();
}
