
/*                         */
/* Program Name: strncat.c */
/*                         */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *source,*dest;
   size_t maxlen;
   printf("Enter two strings which you want to"
   " concate\n");
   printf("First string: ");
   gets(dest);
   printf("Second string: ");
   gets(source);
   printf("How many char of first string concate to second"
                                                 "string: ");
   scanf("%d",&maxlen);
   strncat(dest,source,maxlen);
   printf("Concatenated string: %s",dest);
}
