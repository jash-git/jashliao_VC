
/*                      */
/* Program Name: ltoa.c */
/*                      */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *buffer, *convert_string;
   long convert_value;
   int radix;
   printf("Please input a long integer number:");
   scanf("%s",convert_string);
   printf("Please input the radix:");
   scanf("%d",&radix);
   convert_value=atol(convert_string);
   ltoa(convert_value,buffer,radix);
   printf("You enter %ld in radix %d = %s\n",convert_value,
                                              radix,buffer);
}
