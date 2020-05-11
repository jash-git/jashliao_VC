
/*                      */
/* Program Name: sqrt.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   double x,sqrt_val;
   printf("Enter the number that you want to evaluate"
   " its square root\n");
   printf("Number:");
   scanf("%s",convert_string);
   x=atof(convert_string);
   sqrt_val=sqrt(x);
   printf("SQRT(%g) = %g\n",x,sqrt_val);
}
