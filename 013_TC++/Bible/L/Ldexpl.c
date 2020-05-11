
/*                        */
/* Program Name: ldexpl.c */
/*                        */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   long double mantissa,ldexp_val;
   int exponent;
   printf("Enter (mantissa*úB) that you want to compute"
   " number\n");
   printf("Mantissa:");
   scanf("%s",convert_string);
   mantissa=_atold(convert_string);
   printf("Exponent:");
   scanf("%s",convert_string);
   exponent=atoi(convert_string);
   ldexp_val=ldexp(mantissa,exponent);
   printf("%Lg raises 2 by a power of %d = %Lg\n",mantissa,
                                        exponent,ldexp_val);
}
