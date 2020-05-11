
/*                         */
/* Program Name: asctime.c */
/*                         */
#include <stdio.h>
#include <time.h>

void main(void)
{
   struct tm *currenttime;
   time_t bintime;
   time(&bintime);
   currenttime=localtime(&bintime);
   printf("Current time: %s\n", asctime(currenttime));
}
