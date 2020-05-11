/*                        */
/* Program Name : cputs.c */
/*                        */

#include <stdio.h>
#include <conio.h>

void main()
{
   char *str = "This is a test.";

   clrscr();
   window(10, 10, 60, 20);
   cputs(str);
   window(1, 1, 80, 25);

   printf("\nPress any key to continue...");
   getch();
}
