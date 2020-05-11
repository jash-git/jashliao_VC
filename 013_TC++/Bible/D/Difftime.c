
/*                          */
/* Program Name: difftime.c */
/*                          */
#include <stdio.h>
#include <time.h>
#include <dos.h>
#include <conio.h>

void main(void)
{
   time_t t_start,t_end;
   t_start=time(NULL);
   delay(2000);
   t_end=time(NULL);
   printf("The program ran in %g seconds",
                  difftime(t_end,t_start));
}
