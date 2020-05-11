/*                           */
/* Program Name : _bi_msiz.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <bios.h>

void main()
{
   clrscr();

   printf("This system has %uK bytes memory.\n", _bios_memsize());

   printf("\nPress any key to continue...");
   getch();
}
