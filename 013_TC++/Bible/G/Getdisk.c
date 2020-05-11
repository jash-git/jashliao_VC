/*                          */
/* Program Name : getdisk.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dir.h>

void main()
{
   clrscr();

   printf("Current disc drive is %c:\n", getdisk() + 'A');

   printf("\nPress any key to continue...");
   getch();
}
