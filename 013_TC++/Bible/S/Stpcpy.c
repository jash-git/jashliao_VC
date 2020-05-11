
/*                        */
/* Program Name: stpcpy.c */
/*                        */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *dest,*source;
   printf("Enter source string: ");
   gets(source);
   stpcpy(dest,source);
   printf("Source string is copied to destination"
                                      " string\n");
   printf("Destination string is: %s\n",dest);
}
