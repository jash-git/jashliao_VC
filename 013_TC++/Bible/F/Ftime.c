
/*                       */
/* Program Name: ftime.c */
/*                       */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys\timeb.h>

char *tzstr="TZ=PST3PDT";

void main(void)
{
   struct timeb t;
   putenv(tzstr);
   tzset();
   ftime(&t);
   printf("Seconds since 1/1/1970 GMT: %ld\n",t.time);
   printf("Thousandths of a second: %d\n",t.millitm);
   printf("Difference between local time and GMT: %d\n",
                                             t.timezone);
   printf("Daylight savings in effect (1) not (0): %d\n",
                                               t.dstflag);
}
