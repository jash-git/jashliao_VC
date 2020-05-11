/*                            */
/*  Program Name: _d_getdv.c  */
/*                            */
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   unsigned drive;

   clrscr();

   _dos_getdrive(&drive);
   printf("Current disc drive is %c:\n", drive + 'A' - 1);

   printf("\nPress any key to continue...\n");
   getch();
}
