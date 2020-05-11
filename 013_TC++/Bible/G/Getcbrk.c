/*                          */
/* Program Name : getcbrk.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   clrscr();
   if (getcbrk() == 1)
      printf("Current ctrl-break checking state is on.\n");
   else
      printf("Current ctrl-break checking state is off.\n");

   printf("\nPress any key to continue...");
   getch();
}
