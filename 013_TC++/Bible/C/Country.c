/*                          */
/* Program Name : country.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   struct country cp;

   clrscr();

   printf("Get current country information...\n");
   country(0, &cp);
   printf("Current currency symbol is : %s\n", cp.co_curr);

   printf("\nPress any key to continue...");
   getch();
}
