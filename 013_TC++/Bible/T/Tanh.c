
/*                      */
/* Program Name: tanh.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   double value,tanh_val;
   printf("Enter value whose hyperbolic tangent you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   tanh_val=tanh(value/RadianToDegree);
   printf("Hyperbolic tangent (%g) = %g\n",value,tanh_val);
}
