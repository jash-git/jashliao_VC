/*                          */
/* Program Name : inportb.c */
/*                          */

#include <dos.h>
#include <stdio.h>
#include <conio.h>

#define  PORT_8259_20 0x20
#define  PORT_8259_21 0x21

void main()
{
   clrscr();
   printf("Current data at register 0x20 is %02X\n",
          inportb(PORT_8259_20));

   printf("Current data at register 0x21 is %02X\n",
          inportb(PORT_8259_21));

   printf("\nPress any key to continue...");
   getch();
}
