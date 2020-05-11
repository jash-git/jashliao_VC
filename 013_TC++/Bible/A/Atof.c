
/*                      */
/* Program Name: atof.c */
/*                      */
#include <stdio.h>
#include <math.h>

void main(void)
{
   char *convert_string;
   double converted_value;
   printf("Please input a double floating-point number:");
   scanf("%s",convert_string);
   converted_value=atof(convert_string);
   printf("Converted value = %g\n",converted_value);
}
