
/*                      */
/* Program Name: cabs.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   struct complex z;
   double cabs_val;
   printf("Enter real and imaginary of complex number\n");
   printf("Real:");
   scanf("%le",&z.x);
   printf("Imaginary:");
   scanf("%le",&z.y);
   cabs_val=cabs(z);
   if (errno!=EDOM)
      printf("Absolute of %g%+gi = %g\n",z.x,z.y,cabs_val);
   else
      printf("Input error");
}
