
/*                      */
/* Program Name: expl.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   long double value,exp_val;
   printf("Enter the number that you want to evaluate"
   " its exponential\n");
   printf("Number:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   exp_val=expl(value);
   printf("EXP(%Lg) = %Lg\n",value,exp_val);
}
