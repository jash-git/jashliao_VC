
/*                       */
/* Program Name: frexp.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   int exponent;
   double number,mantissa;
   printf("Enter the number that you want to evaluate\n");
   printf("Number:");
   scanf("%s",convert_string);
   number=atof(convert_string);
   mantissa=frexp(number,&exponent);
   printf("Number %g is %g times two to the power of %d\n",
                                  number,mantissa,exponent);
}
