/*                          */
/* Program Name : gettime.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   struct time timeinfo;

   clrscr();
   printf("Get system time...\n");
   gettime(&timeinfo);

   printf("Current hour   : %d\n", timeinfo.ti_hour);
   printf("Current minute : %d\n", timeinfo.ti_min);
   printf("Current second : %d\n", timeinfo.ti_sec);
   printf("Current hundredth of a second : %d\n", timeinfo.ti_hund);

   printf("\nPress any key to continue...");
   getch();
}
