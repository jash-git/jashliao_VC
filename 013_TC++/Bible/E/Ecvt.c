
/*                      */
/* Program Name: ecvt.c */
/*                      */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *buffer,*convert_string;
   double convert_value=0;
   int dec,sign;
   int count=5;
   printf("Please input a double floating-point number:");
   scanf("%s",convert_string);
   convert_value=atof(convert_string);
   buffer=ecvt(convert_value,count,&dec,&sign);
   printf("Buffer of string from ecvt contain:%s\n",buffer);
   printf("Position of the decimal point:%d\n",dec);
   if (sign==0)
      printf("Sign:positive");
   else
      printf("Sign:negative");
}
