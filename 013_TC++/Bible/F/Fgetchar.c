/*                           */
/* Program Name : fgetchar.c */
/*                           */

#include <stdio.h>
#include <conio.h>

void main()
{
   int  ch;

   clrscr();
   printf("Please enter a character followed by <Enter>\n");

   /* Raead a character from stdin */
   ch = fgetchar();

   printf("The character you entered is %c\n", ch);

   printf("\nPress any key to continue...");
   getch();
}
