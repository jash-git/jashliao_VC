/*                          */
/* Program Name : ungetch.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   char ch = 'C';

   clrscr();
   printf("Push character '%c' back to keyboard buffer...\n", ch);
   ungetch(ch);

   printf("The character in the keyboard buffer is : %c\n", getch());

   printf("\nPress any key to continue...");
   getch();
}
