
/*                      */
/* Program Name: cosl.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   long double value,cos_val;
   printf("Enter value whose cosine you want to evaluate:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   cos_val=cosl(value/RadianToDegree);
   printf("Cosine (%Lg) = %Lg\n",value,cos_val);
}
