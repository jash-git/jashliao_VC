
/*                         */
/* Program Name: strcspn.c */
/*                         */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *s1,*s2;
   size_t length;
   printf("Enter one string: ");
   gets(s1);
   printf("Enter one string which you want to search: ");
   gets(s2);
   length=strcspn(s1,s2);
   printf("Character where strings intersect is at"
                          " position: %d\n",length);
}
