
/*                          */
/* Program Name : settime.c */
/*                          */

#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main()
{
   struct  time t;

   gettime(&t);
   printf("Current time : %02d:%02d:%02d:%02d\n",
        t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);

   /* Add one to the minutes struct element and then
    call settime  */
   t.ti_min++;
   settime(&t);

   puts("After settime() ...");
   gettime(&t);
   printf("Current time : %02d:%02d:%02d:%02d\n",
        t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);

}  /* main() */
