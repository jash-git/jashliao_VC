
/*                      */
/* Program Name: sinl.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   long double value,sin_val;
   printf("Enter value whose sine you want to evaluate:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   sin_val=sinl(value/RadianToDegree);
   printf("Sine (%Lg) = %Lg\n",value,sin_val);
}
