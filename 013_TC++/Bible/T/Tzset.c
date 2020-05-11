
/*                       */
/* Program Name: tzset.c */
/*                       */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
   time_t bintime;
   putenv("TZ=EST5EDT");
   tzset();
   bintime=time(NULL);
   printf("Current time:%s\n",asctime(localtime(&bintime)));
}
