
/*                        */
/* Program Name: strtol.c */
/*                        */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *convert_string,*stop_at;
   long convert_value;
   int radix;
   printf("Enter a long integer:");
   scanf("%s",convert_string);
   printf("Enter the radix:");
   scanf("%d",&radix);
   convert_value=strtol(convert_string,&stop_at,radix);
   printf("You enter value read in radix %d = %ld\n",radix,
                                             convert_value);
   printf("After converting, stopped at: %s\n",stop_at);
}
