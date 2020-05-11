
/*                         */
/* Program Name: isalnum.c */
/*                         */
#include <stdio.h>
#include <ctype.h>

void main(void)
{
   int c,count;
   printf(" Alphnumeric:\n\n");
   for (count=0,c=0;c<=0x7f;c++) {
      if (isprint(c)&&(isalnum(c)!=0)) {
         printf(" %#05d ",c);
         printf(" %c ",c);
         count++;
      }

      if (count==6) {
         printf("\n\n");
         count=0;
      }
   }
}
