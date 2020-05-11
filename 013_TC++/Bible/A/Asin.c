
/*                      */
/* Program Name: asin.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   double value,asin_val;
   printf("Enter value whose arcsine you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   asin_val=asin(value)*RadianToDegree;
   if (errno!=EDOM)
      printf("Arc sine (%g) = %g\n",value,asin_val);
   else
      printf("Input error");
}
