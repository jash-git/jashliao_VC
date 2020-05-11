/*                       */
/* Program Name : putc.c */
/*                       */

#include <stdio.h>
#include <conio.h>

void main()
{
   char *str = "This is a test.";
   int  i;

   clrscr();
   for (i = 0; str[i] != '\0'; i++)
      putc(str[i], stdout);

   printf("\nPress any key to continue...");
   getch();
}
