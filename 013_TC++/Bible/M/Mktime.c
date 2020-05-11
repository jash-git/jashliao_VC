
/*                        */
/* Program Name: mktime.c */
/*                        */
#include <stdio.h>
#include <time.h>

char *wday[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
 "Thursday", "Friday", "Saturday", "Unknown"};

int main(void)
{
   struct tm time_check;
   int year, month, day;
   printf("Year:  ");
   scanf("%d", &year);
   printf("Month: ");
   scanf("%d", &month);
   printf("Day:   ");
   scanf("%d", &day);
   time_check.tm_year = year - 1900;
   time_check.tm_mon  = month - 1;
   time_check.tm_mday = day;
   time_check.tm_hour = 0;
   time_check.tm_min  = 0;
   time_check.tm_sec  = 1;
   time_check.tm_isdst = -1;
   if (mktime(&time_check) == -1)
      time_check.tm_wday = 7;
   printf("That day is a %s\n", wday[time_check.tm_wday]);
   return 0;
}
