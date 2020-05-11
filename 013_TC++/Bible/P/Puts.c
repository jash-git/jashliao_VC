/*                       */
/* Program Name : puts.c */
/*                       */

#include <stdio.h>
#include <conio.h>

void main()
{
   char *str = "This is a test.";

   clrscr();
   puts(str);

   printf("\nPress any key to continue...");
   getch();
}
