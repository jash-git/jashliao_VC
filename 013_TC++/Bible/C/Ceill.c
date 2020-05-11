
/*                       */
/* Program Name: ceill.c */
/*                       */
#include <stdio.h>
#include <math.h>

void main(void)
{
   long double value,ceil_val;
   printf("Enter value whose ceiling value you want to"
   " evaluate:");
   scanf("%Le",&value);
   ceil_val=ceill(value);
   printf("Ceil of %Lg = %Lg\n",value,ceil_val);
}
