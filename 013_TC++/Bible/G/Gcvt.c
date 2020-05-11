
/*                      */
/* Program Name: gcvt.c */
/*                      */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main(void)
{
   char *buffer, *convert_string;
   double convert_value;
   int digits=10;
   printf("Please input a double floating-point number:");
   scanf("%s",convert_string);
   convert_value=atof(convert_string);
   gcvt(convert_value,digits,buffer);
   printf("Buffer of string from gcvt contain:%s\n",buffer);
}
