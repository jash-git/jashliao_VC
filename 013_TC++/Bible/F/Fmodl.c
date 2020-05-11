
/*                       */
/* Program Name: fmodl.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errrno is defined here */

void main(void)
{
   char *convert_string;
   long double numerator,denominator,remainder;
   printf("Enter two floating-point number to caculate"
   " remainder:\n");
   printf("Numerator:");
   scanf("%s",convert_string);
   numerator=_atold(convert_string);
   printf("Denominator:");
   scanf("%s",convert_string);
   denominator=_atold(convert_string);
   remainder=fmodl(numerator,denominator);
   printf("The reaminder of (%Lg/%Lg) = %Lg\n",numerator,
                                   denominator,remainder);
}
