
/*                       */
/* Program Name: srand.c */
/*                       */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
   int i;
   time_t t;
   srand((unsigned) time(&t));
   printf("Ten random integers from 0 to 99:\n");
   for (i=0;i<10;i++) {
       printf("%d\n",random(100));
   }
}
