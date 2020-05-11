
/*                      */
/* Program Name: labs.c */
/*                      */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   long value,labs_val;
   printf("Please input a long integer number:");
   scanf("%ld",&value);
   labs_val=labs(value);
   printf("Absolute value of %ld = %ld\n",value,labs_val);
}
