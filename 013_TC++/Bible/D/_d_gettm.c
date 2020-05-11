/*                           */
/* Program Name : _d_gettm.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   struct dostime_t timeinfo;

   clrscr();
   printf("Get system time...\n");
   _dos_gettime(&timeinfo);

   printf("Current hour   : %d\n", timeinfo.hour);
   printf("Current minute : %d\n", timeinfo.minute);
   printf("Current second : %d\n", timeinfo.second);
   printf("Current hundredth of a second : %d\n", timeinfo.hsecond);

   printf("\nPress any key to continue...");
   getch();
}
