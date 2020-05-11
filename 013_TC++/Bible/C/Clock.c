
/*                       */
/* Program Name: clock.c */
/*                       */
#include <stdio.h>
#include <time.h>

void main(void)
{
   int i,count=1000000;
   double a,b,c,d;
   unsigned t_used;
   clock_t t_start,t_end;
   t_start=clock();
   for (i=0;i<count;i++) {
      a=(double)(i-1);
      b=(double)(i+1);
      c=(double)(i*1);
      d=a*b-c;
   }
   t_end=clock();
   t_used=(t_end-t_start)/CLK_TCK;
   printf("1000000 loops ran for %u seconds\n",t_used);
}
