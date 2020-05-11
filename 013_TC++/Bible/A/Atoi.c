
/*                      */
/* Program Name: atoi.c */
/*                      */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *convert_string;
   int converted_value;
   printf("Please input an integer number:");
   scanf("%s",convert_string);
   converted_value=atoi(convert_string);
   printf("Converted_value = %d\n",converted_value);
}
