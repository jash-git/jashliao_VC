
/*                         */
/* Program Name: strrchr.c */
/*                         */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *string,*ptr;
   int c;
   printf("Enter one string: ");
   gets(string);
   printf("Enter one character which you want to search: ");
   scanf("%c",&c);
   ptr=strrchr(string,c);
   if (ptr) {
      printf("The character %c is at position: %d\n",c,
                                            ptr-string);
   }
   else
      printf("The character %c was not found\n",c);
}
