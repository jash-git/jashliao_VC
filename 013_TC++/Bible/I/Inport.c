/*                         */
/* Program Name : inport.c */
/*                         */

#include <dos.h>
#include <stdio.h>
#include <conio.h>

#define  PORT_8259_20 0x20

void main()
{
   clrscr();
   printf("Current data from register 0x20 is %X\n",
          inport(PORT_8259_20));

   printf("\nPress any key to continue...");
   getch();
}
