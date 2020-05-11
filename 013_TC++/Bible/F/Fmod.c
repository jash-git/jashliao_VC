
/*                      */
/* Program Name: fmod.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errrno is defined here */

void main(void)
{
   char *convert_string;
   double numerator,denominator,remainder;
   printf("Enter two floating-point number to caculate"
   " remainder:\n");
   printf("Numerator:");
   scanf("%s",convert_string);
   numerator=atof(convert_string);
   printf("Denominator:");
   scanf("%s",convert_string);
   denominator=atof(convert_string);
   remainder=fmod(numerator,denominator);
   printf("The reaminder of (%g/%g) = %g\n",numerator,
                                denominator,remainder);
}
