
/*                         */
/* Program Name: strncpy.c */
/*                         */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *dest,*source;
   size_t maxlen;
   printf("Enter source string: ");
   gets(source);
   printf("How many character you want to copy to"
                          " destination string: ");
   scanf("%d",&maxlen);
   strncpy(dest,source,maxlen);
   printf("Destination string is: %s\n",dest);
}
