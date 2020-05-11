
/*                       */
/* Program Name: atanl.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   long double value,atan_val;
   printf("Enter value whose arctangent you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   atan_val=atanl(value)*RadianToDegree;
   if (errno!=EDOM)
      printf("Arc tangent (%Lg) = %Lg\n",value,atan_val);
   else
      printf("Input error");
}
