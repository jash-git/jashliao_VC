
/*                      */
/* Program Name: itoa.c */
/*                      */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *buffer, *convert_string;
   int convert_value,radix;
   printf("Please input an integer number:");
   scanf("%s",convert_string);
   printf("Please input the radix:");
   scanf("%d",&radix);
   convert_value=atoi(convert_string);
   itoa(convert_value,buffer,radix);
   printf("You enter %d in radix %d = %s\n",convert_value,
                                             radix,buffer);
}
