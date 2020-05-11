
/*                       */
/* Program Name: ctime.c */
/*                       */
#include <stdio.h>
#include <time.h>

void main(void)
{
   time_t bintime;
   bintime=time(NULL);
   printf("Today's date and time: %s\n",ctime(&bintime));
}
