
/*                        */
/* Program Name: strset.c */
/*                        */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *string;
   int ch;
   printf("Enter one string: ");
   gets(string);
   printf("Enter character you want the string set to: ");
   scanf("%c",&ch);
   strset(string,ch);
   printf("Converted string is: %s\n",string);
}
