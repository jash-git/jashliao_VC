
/*                          */
/* Program Name: localtim.c */
/*                          */
#include <stdio.h>
#include <time.h>

void main(void)
{
   time_t current_time;
   struct tm *current_tm;
   time(&current_time);
   current_tm=localtime(&current_time);
   printf("Local Time =%s\n",asctime(current_tm));
}
