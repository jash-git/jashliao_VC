
/*                         */
/* Program Name : strspn.c */
/*                         */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *s1,*s2;
   size_t length;
   printf("Enter one string: ");
   gets(s1);
   printf("Enter other string which you want to search: ");
   gets(s2);
   length=strspn(s1,s2);
   printf("Character where strings different is at"
                          " position: %d\n",length);
}
