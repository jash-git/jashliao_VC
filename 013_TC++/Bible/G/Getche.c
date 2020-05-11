/*                         */
/* Program Name : getche.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   char ch;

   clrscr();
   printf("Please enter a character :");
   ch = getche();
   printf("\nYou entered the character : %c\n", ch);

   printf("\nPress any key to continue...");
   getch();
}
