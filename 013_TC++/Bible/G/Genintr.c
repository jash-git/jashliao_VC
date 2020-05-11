/*                          */
/* Program Name : genintr.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   clrscr();

   _AH = 0x02;
   _DL = 'H';
   geninterrupt(0x21);

   printf("\nPress any key to continue...");
   getch();
}
