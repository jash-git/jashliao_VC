/*                            */
/*  Program Name: __emit__.c  */
/*                            */
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   clrscr();
   printf("Use __emit__() to print a letter 'A' to screen.....\n=>");
   __emit__(0xB2, 0x41, 0xB4, 0x02, 0xCD, 0x21);

   printf("\nPress any key to continue...\n");
   getch();
}
