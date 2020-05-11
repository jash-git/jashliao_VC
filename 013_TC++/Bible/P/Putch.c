/*                        */
/* Program Name : putch.c */
/*                        */

#include <conio.h>
#include <stdio.h>

void main()
{
   int i;

   clrscr();
   window(11, 10, 20, 20);

   for (i = 0; i < 50; i++)
      putch('A');

   window(1, 1, 80, 25);

   printf("\nPress any key to continue...");
   getch();
}
