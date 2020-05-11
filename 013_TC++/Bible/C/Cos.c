
/*                     */
/* Program Name: cos.c */
/*                     */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   double value,cos_val;
   printf("Enter value whose cosine you want to evaluate:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   cos_val=cos(value/RadianToDegree);
   printf("Cosine (%g) = %g\n",value,cos_val);
}
