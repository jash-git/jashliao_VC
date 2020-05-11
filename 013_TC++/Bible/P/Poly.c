
/*                      */
/* Program Name: poly.c */
/*                      */
#include <stdio.h>
#include <math.h>

/* Polynomial is: 3x**2+2x-1 */
void main(void)
{
   double value_at_10;
   double c[]={-1.0, 2.0, 3.0};
   value_at_10=poly(10.0,2,c);
   printf("3x**2+2x-1 evaluate at 10.0 = %f\n",value_at_10);
}
