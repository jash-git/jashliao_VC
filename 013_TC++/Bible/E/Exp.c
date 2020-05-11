
/*                     */
/* Program Name: exp.c */
/*                     */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   double value,exp_val;
   printf("Enter the number that you want to evaluate"
   " its exponential\n");
   printf("Number:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   exp_val=exp(value);
   printf("EXP(%g) = %g\n",value,exp_val);
}
