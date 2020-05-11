/*                         */
/* Program Name : getpsp.c */
/*                         */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   char far *path;
   int  length, count;

   clrscr();
   printf("Get segment address  of PSP...");
   path = MK_FP(getpsp(), 0x80);

   printf("\nThe parameters on the command line : ");
   length = *path;
   for (count = 0; count < length; count++)
      putchar(*(path + count + 1));

   printf("\nPress any key to continue...");
   getch();
}
