/*                           */
/* Program Name : biostime.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <bios.h>

void main()
{
   long cur_sec;
   int sec, min, hour;

   clrscr();

   cur_sec = biostime(0, 0) / CLK_TCK;
   sec  = cur_sec % 60;
   hour = cur_sec / 3600;
   min  = cur_sec / 60 - hour * 60;

   printf("Current time is %2d:%2d:%2d\n", hour, min, sec);

   printf("\nPress any key to continue...");
   getch();
}
