
/*                          */
/* Program Name: _tolower.c */
/*                          */
#include <stdio.h>
#include <ctype.h>

void main(void)
{
   char *in_string;
   int i;
   printf("Enter a string: ");
   scanf("%s",in_string);
   for (i=0;(in_string[i]!=' ')&&(in_string[i]!='\0');i++) {
      in_string[i]=_tolower(in_string[i]);
   }
   printf("Converted string is: %s\n",in_string);
}
