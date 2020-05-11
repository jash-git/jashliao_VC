/*                           */
/* Program Name : fputchar.c */
/*                           */

#include <stdio.h>
#include <conio.h>

void main()
{
   char *str = "This is a test.";
   int  i;

   clrscr();
   for (i = 0; str[i] != '\0'; i++)
      fputchar(str[i]);

   printf("\nPress any key to continue...");
   getch();
}
