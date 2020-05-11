
/*                       */
/* Program Name: stime.c */
/*                       */
#include <stdio.h>
#include <time.h>

void main(void)
{
   struct tm *currenttime;
   time_t bintime;
   time(&bintime);
   currenttime=localtime(&bintime);
   printf("Current time: %s",asctime(currenttime));
   bintime+=86400L;
   stime(&bintime);
   time(&bintime);
   currenttime=localtime(&bintime);
   printf("Time After one day: %s",asctime(currenttime));
}
