
/*                        */
/* Program Name: strrev.c */
/*                        */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *string;
   printf("Enter one string: ");
   gets(string);
   printf("Before strrev(): %s\n",string);
   strrev(string);
   printf("After strrev(): %s\n",string);
}
