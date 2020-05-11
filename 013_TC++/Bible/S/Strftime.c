
/*                          */
/* Program Name: strftime.c */
/*                          */
#include <stdio.h>
#include <time.h>

void main(void)
{
   struct tm *currenttime;
   time_t bintime;
   char str[80];
   time(&bintime);
   currenttime=localtime(&bintime);
   strftime(str,80,"Current time: %I:%M:%S %p ",
                                     currenttime);
   printf("%s\n",str);
}
