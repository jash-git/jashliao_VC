/*                           */
/* Program Name : _d_gdate.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   struct dosdate_t dateinfo;

   clrscr();

   _dos_getdate(&dateinfo);

   printf("Current date is %d-%d-%d\n",
          dateinfo.month, dateinfo.day, dateinfo.year);

   printf("\nPress any key to continue...");
   getch();
}
