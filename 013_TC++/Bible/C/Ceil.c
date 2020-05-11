
/*                      */
/* Program Name: ceil.c */
/*                      */
#include <stdio.h>
#include <math.h>

void main(void)
{
   double value,ceil_val;
   printf("Enter value whose ceiling value you want to"
   " evaluate:");
   scanf("%le",&value);
   ceil_val=ceil(value);
   printf("Ceil of %g = %g\n",value,ceil_val);
}
