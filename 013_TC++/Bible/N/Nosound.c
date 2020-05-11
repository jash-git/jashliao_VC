
/*                          */
/* Program Name : nosound.c */
/*                          */

#include <dos.h>
#include <conio.h>

void main()
{
   clrscr();
   printf("Press a key to test sound(), nosound() !\n");
   getch();
   sound(120);
   delay(1000);
   sound(220);
   delay(1500);
   nosound();
}

