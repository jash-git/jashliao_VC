/*                        */
/* Program Name : delay.c */
/*                        */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   clrscr();
   printf("Now, you can hear a voice......");
   sound(1000);
   delay(5000);
   printf("\n\nNow, it becomes quiet.\n");
   nosound();

   printf("\nPress any key to contunue...");
   getch();
}
