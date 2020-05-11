/*                           */
/* Program Name : _bi_tday.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <bios.h>

void main()
{
   long cur_ticks, cur_secs;
   int sec, min, hour;

   clrscr();

   _bios_timeofday(_TIME_GETCLOCK, &cur_ticks);

   cur_secs = cur_ticks / CLK_TCK;
   sec  = cur_secs % 60;
   hour = cur_secs / 3600;
   min  = cur_secs / 60 - hour * 60;

   printf("Current time is %2d:%2d:%2d\n", hour, min, sec);

   printf("\nPress any key to continue...");
   getch();
}
