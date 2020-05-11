
/*                        */
/* Program Name : peek.c */
/*                        */
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   int value = 0;

   clrscr();
   printf("The current status of your keyboard is:\n");
   value = peek(0x0040, 0x0017);

   if (value & 16)
      printf("Scroll lock on\n");
   else
      printf("Scroll lock off\n");

   if (value & 32)
      printf("Num lock on\n");
   else
      printf("Num lock off\n");

   if (value & 64)
      printf("Caps lock on\n");
   else
      printf("Caps lock off\n");

}
