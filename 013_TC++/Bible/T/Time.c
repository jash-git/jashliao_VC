
/*                      */
/* Program Name: time.c */
/*                      */
#include <stdio.h>
#include <time.h>

void main(void)
{
   time_t current_time;
   current_time=time(NULL);
   printf("The number of seconds since January 1, 1970 is"
                                      " %ld",current_time);
}
