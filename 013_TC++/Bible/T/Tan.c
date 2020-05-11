
/*                     */
/* Program Name: tan.c */
/*                     */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */
#define  RadianToDegree 57.29578

void main(void)
{
   char *convert_string;
   double value,tan_val;
   printf("Enter value whose tangent you want to"
   " evaluate:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   tan_val=tan(value/RadianToDegree);
   printf("Tangent (%g) = %g\n",value,tan_val);
}
