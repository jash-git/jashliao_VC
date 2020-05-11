/*                         */
/* Program Name : getdta.c */
/*                         */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   clrscr();

   printf("Current disc transfer address is %Fp\n", getdta());

   printf("\nPress any key to continue...");
   getch();
}
