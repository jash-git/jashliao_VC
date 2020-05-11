
/*                         */
/* Program Name : strtok.c */
/*                         */

#include <stdio.h>
#include <string.h>

void main(void)
{
   char *s1,*s2=" ",*ptr;
   printf("Enter one string: ");
   gets(s1);
   ptr=strtok(s1,s2);
   while (ptr!=NULL) {
      printf("The substring is: %s\n",ptr);
      ptr=strtok(NULL,s2);
   }
}
