
/*                        */
/* Program Name: hypotl.c */
/*                        */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* errno is defined here */

void main(void)
{
   char *convert_string;
   long double x, y, hypotenuse;
   printf("Enter 2 sides of a right triangle to compute its"
   " hypotenuse\n");
   printf("First side:");
   scanf("%s",convert_string);
   x=_atold(convert_string);
   printf("Second side:");
   scanf("%s",convert_string);
   y=_atold(convert_string);
   hypotenuse=hypotl(x,y);
   printf("The Hypotenuse = %Lg\n",hypotenuse);
}
