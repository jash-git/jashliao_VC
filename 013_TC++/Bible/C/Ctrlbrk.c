/*                          */
/* Program Name : ctrlbrk.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

int cb_handler(void)
{
   printf("Stop the program!\n\n");
   /* Abort the program running */
   return 0;
}

void main()
{
   int count = 0;
   clrscr();
   ctrlbrk(cb_handler);
   while(1)
      printf("Test %-5d", count++);
}
