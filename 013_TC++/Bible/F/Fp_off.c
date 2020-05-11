/*                         */
/* Program Name : fp_off.c */
/*                         */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   int       test = 100;
   void far *far_pointer;

   clrscr();
   far_pointer = (void far *) &test;

   printf("The offset of variable 'test' is : 0x%X\n",
          FP_OFF(far_pointer));

   printf("\nPress any key to continue...");
   getch();
}
