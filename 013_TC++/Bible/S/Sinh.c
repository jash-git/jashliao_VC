
/*                      */
/* Program Name: sinh.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   double value,sinh_val;
   printf("Enter value whose hyperbolic sine you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   sinh_val=sinh(value/RadianToDegree);
   printf("Hyperbolic sine (%g) = %g\n",value,sinh_val);
}
