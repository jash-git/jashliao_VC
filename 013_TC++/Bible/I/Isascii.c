
/*                         */
/* Program Name: isascii.c */
/*                         */
#include <stdio.h>
#include <ctype.h>

void main(void)
{
   int c;
   printf("Enter an integer number:");
   scanf("%d",&c);
   if (isascii(c)) {
      printf("%c is an ASCII character\n",c);
   }
   else {
      printf("%d is not an ASCII character\n",c);
   }
}
