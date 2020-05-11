
/*                        */
/* Program Name: strcpy.c */
/*                        */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *dest,*source;
   printf("Enter source string: ");
   gets(source);
   strcpy(dest,source);
   printf("Source string is copied to destination"
                                      " string\n");
   printf("Destination string is: %s\n",dest);
}
