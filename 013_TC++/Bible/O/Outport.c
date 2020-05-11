/*                          */
/* Program Name : outport.c */
/*                          */

#include <dos.h>
#include <stdio.h>
#include <conio.h>

#define  PORT_0x0  0x0

void main()
{
   clrscr();
   printf("Write data 'A' to register 0x0...\n");
   outport(PORT_0x0, 'A');

   printf("\nPress any key to continue...");
   getch();
}
