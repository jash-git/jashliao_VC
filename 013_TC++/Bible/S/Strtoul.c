
/*                         */
/* Program Name: strtoul.c */
/*                         */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void main(void)
{
   char *convert_string,*stop_at;
   unsigned long value;
   int radix;
   printf("Enter a number followed by other character:");
   scanf("%s",convert_string);
   printf("Enter the radix:");
   scanf("%d",&radix);
   value=strtoul(convert_string,&stop_at,radix);
   printf("Value read in radix %d = %lu\n",radix,value);
   printf("Stopped at: %s\n",stop_at);
}
