
/*                       */
/* Program Name: atan2.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   double y,x,atan2_val;
   printf("Enter (value y/value x) that arctangent you want"
   " to evaluate\n");
   printf("Value y:");
   scanf("%s",convert_string);
   printf("Value x:");
   y=atof(convert_string);
   scanf("%s",convert_string);
   x=atof(convert_string);
   atan2_val=atan2(y,x)*RadianToDegree;
   if (errno!=EDOM)
      printf("Arc tangent (%g/%g) = %g\n",y,x,atan2_val);
   else
      printf("Input error");
}
