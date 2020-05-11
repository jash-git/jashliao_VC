
/*                        */
/* Program Name : sound.c */
/*                        */

#include <dos.h>
#include <conio.h>
#include <stdio.h>

void main()
{
   clrscr();
   puts("Press a key to listen ...");
   puts("Do");
   sound(523);
   delay(1000);
   puts("Re");
   sound(587);
   delay(1000);
   puts("Mi");
   sound(659);
   delay(1000);
   nosound();
} /* main() */
