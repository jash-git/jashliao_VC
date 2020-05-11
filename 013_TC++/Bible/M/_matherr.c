
/*                         */
/* Program Name: _matherr.c */
/*                         */
#include <stdio.h>
#include <math.h>
#include <string.h>

int matherr(struct exception *);

void main(void)
{
   double x,y=0;
   x=2.0;
   y=sqrt(x);
   printf("Matherr corrected value: %g\n",y);
}

int matherr(struct exception *a)
{
   if (a->type==DOMAIN) {
      if (strcmp(a->name,"sqrt")==0) {
         a->retval=sqrt(-(a->arg1));
         return(1);
      }
   }
   return(0);
}
