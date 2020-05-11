
/*                         */
/* Program Name: floorl.c  */
/*                         */
#include <stdio.h>
#include <math.h>

void main(void)
{
   char *convert_string;
   long double value,floor_val;
   printf("Please input a floating-point number:");
   scanf("%s",convert_string);
   value=_atold(convert_string);
   floor_val=floorl(value);
   printf("Floor of %Lg = %Lg\n",value,floor_val);
}
