
/*                          */
/* Program Name : setdate.c */
/*                          */

#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <dos.h>

void main()
{
   struct date reset;
   struct date save_date;

   clrscr();
   getdate(&save_date);
   printf("Original date:\n");
   system("date");

   reset.da_year = 2001;
   reset.da_day = 1;
   reset.da_mon = 1;
   setdate(&reset);

   printf("Date after setting:\n");
   system("date");

   setdate(&save_date);
   printf("Back to original date:\n");
   system("date");

} /* main() */
