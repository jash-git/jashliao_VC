/*                          */
/* Program Name : getdate.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   struct date dateinfo;

   clrscr();

   getdate(&dateinfo);

   printf("Current date is %d-%d-%d\n",
          dateinfo.da_mon, dateinfo.da_day, dateinfo.da_year);

   printf("\nPress any key to continue...");
   getch();
}
