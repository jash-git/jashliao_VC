/*                          */
/* Program Name : cprintf.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{

   clrscr();

   window(30, 10, 60, 20);
   cprintf("Hi! I am here.");
   window(1, 1, 80, 25);

   printf("\nPress any key to continue...");
   getch();
}
