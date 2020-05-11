/*                           */
/* Program Name : dos2unix.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <time.h>

void main()
{
   struct date d;
   struct time t;
   struct tm   *local;
   long   unix_time;

   getdate(&d);
   gettime(&t);

   unix_time = dostounix(&d, &t);
   local = localtime(&unix_time);

   clrscr();
   printf("Current time in UNIX format is : %ld\n", unix_time);
   printf("Current time in DOS format is  : %s\n", asctime(local));

   printf("Press any key to contunue...");
   getch();
}
