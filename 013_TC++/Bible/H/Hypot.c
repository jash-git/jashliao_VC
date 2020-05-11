
/*                       */
/* Program Name: hypot.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */

void main(void)
{
   char *convert_string;
   double x, y, hypotenuse;
   printf("Enter 2 sides of a right triangle to compute its"
   " hypotenuse\n");
   printf("First side:");
   scanf("%s",convert_string);
   x=atof(convert_string);
   printf("Second side:");
   scanf("%s",convert_string);
   y=atof(convert_string);
   hypotenuse=hypot(x,y);
   printf("The Hypotenuse = %g\n",hypotenuse);
}
