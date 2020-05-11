
/*                       */
/* Program Name: ldexp.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   double mantissa,ldexp_val;
   int exponent;
   printf("Enter (mantissa*úC) that you want to compute"
   " number\n");
   printf("Mantissa:");
   scanf("%s",convert_string);
   mantissa=atof(convert_string);
   printf("Exponent:");
   scanf("%s",convert_string);
   exponent=atoi(convert_string);
   ldexp_val=ldexp(mantissa,exponent);
   printf("%g raises 2 by a power of %d = %g\n",mantissa,
                                      exponent,ldexp_val);
}
