
/*                        */
/* Program Name: strlen.c */
/*                        */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *string;
   printf("Enter one string to caculate its length: ");
   gets(string);
   printf("Length of string:%s = %d",string,strlen(string));
}
