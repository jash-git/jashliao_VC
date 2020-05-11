
/*                      */
/* Program Name: atan.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   double value,atan_val;
   printf("Enter value whose arctangent you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   atan_val=atan(value)*RadianToDegree;
   if (errno!=EDOM)
      printf("Arc tangent (%g) = %g\n",value,atan_val);
   else
      printf("Input error");
}
