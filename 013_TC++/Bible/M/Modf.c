
/*                      */
/* Program Name: modf.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errrno is defined here */

void main(void)
{
   char *convert_string;
   double value,intpart,fract;
   printf("Enter one floating-point number:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   fract=modf(value,&intpart);
   printf("The integer and fractional parts of %g are %g"
                         " and %g\n",value,intpart,fract);
}
