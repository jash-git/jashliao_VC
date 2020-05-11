
/*                        */
/* Program Name: gmtime.c */
/*                         */
#include <stdio.h>
#include <time.h>

void main(void)
{
   time_t current_time;
   struct tm *current_tm;
   time(&current_time);
   current_tm=gmtime(&current_time);
   printf("Greenwich Mean Time =%s\n",asctime(current_tm));
}
