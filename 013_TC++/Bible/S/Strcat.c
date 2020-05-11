
/*                        */
/* Program Name: strcat.c */
/*                        */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *source,*dest;
   printf("Enter two strings which you want to"
   " concate\n");
   printf("First string: ");
   gets(dest);
   printf("Second string: ");
   gets(source);
   strcat(dest,source);
   printf("Concatenated string: %s",dest);
}
