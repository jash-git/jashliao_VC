
/*                      */
/* Program Name: logl.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   long double x,log_val;
   printf("Enter the number that you want to compute its"
   " natural log\n");
   printf("Number:");
   scanf("%s",convert_string);
   x=_atold(convert_string);
   log_val=logl(x);
   if (errno!=EDOM && errno!=ERANGE) {
      printf("The natural log of %Lg is %Lg\n",x,log_val);
   }
}
