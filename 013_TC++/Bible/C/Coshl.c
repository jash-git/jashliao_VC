
/*                             */
/*    Program Name: coshl.c    */
/*                             */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   long double value,cosh_val;
   printf("Enter value whose hyperbolic cosine you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   cosh_val=coshl(value/RadianToDegree);
   printf("Hyperbolic cosine (%Lg) = %Lg\n",value,cosh_val);
}
