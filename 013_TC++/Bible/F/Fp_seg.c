/*                         */
/* Program Name : fp_seg.C */
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

   printf("The segment of variable 'test' is : 0x%X\n",
          FP_SEG(far_pointer));

   printf("\nPress any key to continue...");
   getch();
}
