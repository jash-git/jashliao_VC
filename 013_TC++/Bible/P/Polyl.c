
/*                       */
/* Program Name: polyl.c */
/*                       */
#include <stdio.h>
#include <math.h>

/* Polynomial is: 3x**2+2x-1 */
void main(void)
{
   long double value_at_10;
   long double c[]={-1.0, 2.0, 3.0};
   value_at_10=polyl(10.0,2,c);
   printf("3x**2+2x-1 evaluate at 10.0=%Lg\n",value_at_10);
}
