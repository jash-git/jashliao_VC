
/*                     */
/* Program Name: log.c */
/*                     */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   double x,log_val;
   printf("Enter the number that you want to compute its"
   " natural log\n");
   printf("Number:");
   scanf("%s",convert_string);
   x=atof(convert_string);
   log_val=log(x);
   if (errno!=EDOM && errno!=ERANGE) {
      printf("The natural log of %g is %g\n",x,log_val);
   }
}
