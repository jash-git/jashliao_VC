
/*                       */
/* Program Name: floor.c */
/*                       */
#include <stdio.h>
#include <math.h>

void main(void)
{
   char *convert_string;
   double value,floor_val;
   printf("Please input a floating-point number:");
   scanf("%s",convert_string);
   value=atof(convert_string);
   floor_val=floor(value);
   printf("Floor of %g = %g\n",value,floor_val);
}
