
/*                      */
/* Program Name: cosh.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   double value,cosh_val;
   printf("Enter value whose hyperbolic cosine you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   cosh_val=cosh(value/RadianToDegree);
   printf("Hyperbolic cosine (%g) = %g\n",value,cosh_val);
}
