
/*                      */
/* Program Name: fabs.c */
/*                      */
#include <stdio.h>
#include <math.h>

void main(void)
{
   char *convert_string;
   double value,fabs_val;
   printf("Please input a floating-point number:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   fabs_val=fabs(value);
   printf("Absolute value of %g = %g\n",value,fabs_val);
}
