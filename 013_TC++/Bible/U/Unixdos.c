
/*                          */
/* Program Name : unixdos.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

char *month[] = {"---", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

#define SECONDS_PER_DAY 86400L  /* the number of seconds in one day */

struct date dt;
struct time tm;

void main()
{
   unsigned long val;

   clrscr();
/* get today's date and time */
   getdate(&dt);
   gettime(&tm);
   printf("Today is %d %s %d\n", dt.da_day,
           month[dt.da_mon], dt.da_year);

/* convert date and time to unix format (num of
   seconds since Jan 1, 1970 */
   val = dostounix(&dt, &tm);

/* subtract 42 days worth of seconds */
   val -= (SECONDS_PER_DAY * 42);

/* convert back to dos time and date */
   unixtodos(val, &dt, &tm);
   printf("42 days ago it was %d %s %d\n",
          dt.da_day, month[dt.da_mon], dt.da_year);

} /* main() */
