/*                       */
/* Program Name : outp.c */
/*                       */

#include <stdio.h>
#include <conio.h>

#define  PORT_0x0  0x0

void main()
{
   clrscr();
   printf("Write data 'A' to register 0x0...\n");
   outp(PORT_0x0, (int) 'A');

   printf("\nPress any key to continue...");
   getch();
}
