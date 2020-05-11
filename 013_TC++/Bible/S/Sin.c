
/*                     */
/* Program Name: sin.c */
/*                     */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   double value,sin_val;
   printf("Enter value whose sine you want to evaluate:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   sin_val=sin(value/RadianToDegree);
   printf("Sine (%g) = %g\n",value,sin_val);
}
