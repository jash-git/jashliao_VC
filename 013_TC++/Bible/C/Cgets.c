/*                        */
/* Program Name : cgets.c */
/*                        */

#include <stdio.h>
#include <conio.h>

void main()
{
   char msg[82];

   msg[0] = 80; /* set maximum allowable chars */
   clrscr();
   printf("Please enter a line:\n");
   cgets(msg);

   printf("\nThe line you entered is : %s\n", &msg[2]);
   printf("Total %d characters read.\n", msg[1]);

   printf("\nPress any key to continue...");
   getch();
}
