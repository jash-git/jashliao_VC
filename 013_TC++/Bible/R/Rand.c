
/*                      */
/* Program Name: rand.c */
/*                      */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   int i;
   printf("Five random integers:");
   for (i=0;i<5;i++) {
       printf("%d\n",rand());
   }
}
