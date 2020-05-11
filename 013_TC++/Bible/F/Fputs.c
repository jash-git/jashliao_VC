/*                        */
/* Program Name : fputs.c */
/*                        */

#include <stdio.h>
#include <conio.h>

void main()
{
   char *str = "This is a test.";

   clrscr();
   fputs(str, stdout);

   printf("\nPress any key to continue...");
   getch();
}
