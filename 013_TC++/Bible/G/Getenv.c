/*                         */
/* Program Name : getenv.c */
/*                         */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
   clrscr();

   printf("Current path=%s\n", getenv("PATH"));

   printf("\nPress any key to continue...");
   getch();
}
