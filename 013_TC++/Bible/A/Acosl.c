
/*                       */
/* Program Name: acosl.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   long double value,acos_val;
   printf("Enter value whose arccosine you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   acos_val=acosl(value)*RadianToDegree;
   if (errno!=EDOM)
      printf("Arc cosine (%Lg) = %Lg\n",value,acos_val);
   else
      printf("Input error");
}
