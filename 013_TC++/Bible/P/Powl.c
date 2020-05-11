
/*                      */
/* Program Name: powl.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   int exponent;
   long double x,y,pow_val;
   printf("Enter two number that you want to evaluate"
   " x^y\n");
   printf("X:");
   scanf("%s",convert_string);
   x=_atold(convert_string);
   printf("Y:");
   scanf("%s",convert_string);
   y=_atold(convert_string);
   pow_val=powl(x,y);
   printf("%Lg raised to %Lg is %Lg\n",x,y,pow_val);
}
