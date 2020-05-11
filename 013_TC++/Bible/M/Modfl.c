
/*                       */
/* Program Name: modfl.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errrno is defined here */

void main(void)
{
   char *convert_string;
   long double value,intpart,fract;
   printf("Enter one floating-point number:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   fract=modfl(value,&intpart);
   printf("The integer and fractional parts of %Lg are %Lg"
                          " and %Lg\n",value,intpart,fract);
}
