
/*                       */
/* Program Name: cabsl.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   struct complex z;
   long double cabs_val;
   printf("Enter real and imaginary of complex number\n");
   printf("Real:");
   scanf("%Le",&z.x);
   printf("Imaginary:");
   scanf("%Le",&z.y);
   cabs_val=cabsl(z);
   if (errno!=EDOM)
      printf("Absolute of %Lg%+Lgi=%Lg\n",z.x,z.y,cabs_val);
   else
      printf("Input error");
}
