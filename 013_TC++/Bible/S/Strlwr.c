
/*                        */
/* Program Name: strlwr.c */
/*                        */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *string;
   printf("Enter one string which you want to convert it"
                                     " into lowercase\n");
   printf("Input string: ");
   gets(string);
   strlwr(string);
   printf("Converted string: %s",string);
}
