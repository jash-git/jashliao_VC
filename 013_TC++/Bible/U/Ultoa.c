
/*                       */
/* Program Name: ultoa.c */
/*                       */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *buffer, *convert_string;
   unsigned long convert_value;
   int radix;
   printf("Please input an unsigned long integer number:");
   scanf("%s",convert_string);
   printf("Please input the radix:");
   scanf("%d",&radix);
   convert_value=atol(convert_string);
   ultoa(convert_value,buffer,radix);
   printf("You enter %lu in radix %d = %s\n",convert_value,
                                              radix,buffer);
}
