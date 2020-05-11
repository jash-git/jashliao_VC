
/*                       */
/* Program Name: fabsl.c */
/*                       */
#include <stdio.h>
#include <math.h>

void main(void)
{
   char *convert_string;
   long double value,fabs_val;
   printf("Please input a floating-point number:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   fabs_val=fabsl(value);
   printf("Absolute value of %Lg = %Lg\n",value,fabs_val);
}
