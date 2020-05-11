
/*                         */
/* Program Name : strstr.c */
/*                         */

#include <stdio.h>
#include <string.h>

void main(void)
{
   char *s1,*s2,*ptr;
   int c;
   printf("Enter one string: ");
   gets(s1);
   printf("Enter other string which you want to search: ");
   gets(s2);
   ptr=strstr(s1,s2);
   if (ptr) {
      printf("The string %s is at position: %d\n",s2,
                                              ptr-s1);
   }
   else
      printf("The character %s was not found\n",s2);
}
