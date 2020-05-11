/*                          */
/* Program Name : getvect.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   clrscr();
   printf("Interrupt vector addresses of 0x05 is : %Fp",
          getvect(0x05));

   printf("\nPress any key to continue...");
   getch();
}
