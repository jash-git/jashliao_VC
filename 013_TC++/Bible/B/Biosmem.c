/*                             */
/* Program Name : biosmemory.c */
/*                             */

#include <stdio.h>
#include <conio.h>
#include <bios.h>

void main()
{
   clrscr();

   printf("This system has %dK bytes memory.\n", biosmemory());

   printf("\nPress any key to continue...");
   getch();
}
