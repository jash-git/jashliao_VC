
/*                         */
/* Program Name: toascii.c */
/*                         */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main(void)
{
   int c,ascii_ch;
   printf("Enter an integer number convert to ASCII:");
   scanf("%d",&c);
   ascii_ch=toascii(c);
   printf("%d is converted to ASCII character %c\n",c,
                                             ascii_ch);
}
