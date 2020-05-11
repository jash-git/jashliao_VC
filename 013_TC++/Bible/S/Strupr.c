
/*                         */
/* Program Name : strupr.c */
/*                         */

#include <stdio.h>
#include <string.h>

void main(void)
{
   char *string;
   printf("Enter one string which you want to convert it"
                                     " into uppercase\n");
   printf("Input string: ");
   gets(string);
   strupr(string);
   printf("Converted string: %s",string);
}
