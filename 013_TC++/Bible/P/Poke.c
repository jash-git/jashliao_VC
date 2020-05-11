
/*                       */
/* Program Name : poke.c */
/*                       */
#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main()
{
   clrscr();
   puts("Turn off the scroll lock key and press any key ...");
   getch();
   poke(0x0000,0x0417,16);
   puts("Now the scroll lock is on !");
}
