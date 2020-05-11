
/*                     */
/* Program Name: pow.c */
/*                     */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   int exponent;
   double x,y,pow_val;
   printf("Enter two number that you want to evaluate"
   " x^y\n");
   printf("X:");
   scanf("%s",convert_string);
   x=atof(convert_string);
   printf("Y:");
   scanf("%s",convert_string);
   y=atof(convert_string);
   pow_val=pow(x,y);
   printf("%g raised to %g is %g\n",x,y,pow_val);
}
