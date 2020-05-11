
/*                        */
/* Program Name: strdup.c */
/*                        */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *dup_str,source[80];
   printf("Enter source string: ");
   gets(source);
   dup_str=strdup(source);
   printf("Destination string is: %s\n",dup_str);
   printf("Freeing the space allocated by strdup\n");
   free(dup_str);
}
