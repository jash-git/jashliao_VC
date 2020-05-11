/*                       */
/* Program Name : gets.c */
/*                       */

#include <stdio.h>
#include <conio.h>

void main()
{
   char msg[81];

   printf("Please enter a line:\n");
   gets(msg);

   printf("The line you entered is : %s\n", msg);

   printf("\nPress any key to continue...");
   getch();
}
