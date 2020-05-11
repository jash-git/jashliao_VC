
/*                       */
/* Program Name: log10.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   double x, log10_val;
   printf("Enter the number that you want to compute its"
   " log10\n");
   printf("Number:");
   scanf("%s",convert_string);
   x=atof(convert_string);
   log10_val=log10(x);
   if (errno!=EDOM && errno!=ERANGE) {
      printf("The log10 of %g is %g\n",x,log10_val);
   }
}
