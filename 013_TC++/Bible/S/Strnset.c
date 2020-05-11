
/*                         */
/* Program Name: strnset.c */
/*                         */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *string;
   int ch;
   size_t n;
   printf("Enter one string: ");
   gets(string);
   printf("Enter character you want the string set to: ");
   scanf("%c",&ch);
   printf("How many character you want to set to: ");
   scanf("%d",&n);
   strnset(string,ch,n);
   printf("Converted string is: %s\n",string);
}
