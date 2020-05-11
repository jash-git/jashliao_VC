
/*                       */
/* Program Name: sinhl.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   long double value,sinh_val;
   printf("Enter value whose hyperbolic sine you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   sinh_val=sinhl(value/RadianToDegree);
   printf("Hyperbolic sine (%Lg) = %Lg\n",value,sinh_val);
}
