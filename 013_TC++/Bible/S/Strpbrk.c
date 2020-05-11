
/*                         */
/* Program Name: strpbrk.c */
/*                         */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *s1,*s2,*position;
   printf("Enter one string: ");
   gets(s1);
   printf("Enter one string which you want to search: ");
   gets(s2);
   position=strpbrk(s1,s2);
   printf("Character where strings intersect is at"
                          " position: %d\n",position-s1);
}
