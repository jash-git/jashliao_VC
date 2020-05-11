
/*                       */
/* Program Name: sqrtl.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   long double x,sqrt_val;
   printf("Enter the number that you want to evaluate"
   " its square root\n");
   printf("Number:");
   scanf("%s",convert_string);
   x=_atold(convert_string);
   sqrt_val=sqrtl(x);
   printf("SQRT(%Lg) = %Lg\n",x,sqrt_val);
}
