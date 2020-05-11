
/*                      */
/* Program Name: atol.c */
/*                      */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *convert_string;
   long converted_value;
   printf("Please input a long integer number:");
   scanf("%s",convert_string);
   converted_value=atol(convert_string);
   printf("Converted value = %ld\n",converted_value);
}
