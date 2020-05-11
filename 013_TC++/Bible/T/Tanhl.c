
/*                       */
/* Program Name: tanhl.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   long double value,tanh_val;
   printf("Enter value whose hyperbolic tangent you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   tanh_val=tanhl(value/RadianToDegree);
   printf("Hyperbolic tangent (%Lg)=%Lg\n",value,tanh_val);
}
