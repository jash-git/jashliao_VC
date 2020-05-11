
/*                      */
/* Program Name: tanl.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   long double value,tan_val;
   printf("Enter value whose tangent you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   tan_val=tanl(value/RadianToDegree);
   printf("Tangent (%Lg) = %Lg\n",value,tan_val);
}
