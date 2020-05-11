
/*                          */
/* Program Name : strxfrm.c */
/*                          */

#include <stdio.h>
#include <string.h>

void main(void)
{
   char *dest,*source;
   size_t maxchr,length;
   printf("Enter source string: ");
   gets(source);
   printf("How many char you want to copy to"
                         " destination string: ");
   scanf("%d",&maxchr);
   length=strxfrm(dest,source,maxchr);
   printf("Destination string is: %s\n",dest);
}
