/*                         */
/* Program Name : ungetc.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   int ch;

   clrscr();

   printf("Please enter a character :\n");
   ch = getchar();

   printf("put back the character to the buffer of stdin...\n");
   ungetc(ch, stdin);

   printf("The character got from the buffer is :%c\n", getchar());

   printf("\nPress any key to continue...");
   getch();
}
