
/*                        */
/* Program Name: frexpl.c */
/*                        */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   int exponent;
   long double number,mantissa;
   printf("Enter the number that you want to evaluate\n");
   printf("Number:");
   scanf("%s",convert_string);
   number=_atold(convert_string);
   mantissa=frexpl(number,&exponent);
   printf("Number %Lg is %Lg times two to the power of %d\n"
                                 ,number,mantissa,exponent);
}
