
/*                          */
/* Program Name: randomiz.c */
/*                          */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
   int i;
   /* Initialize the random number generator */
   randomize();
   printf("Ten random numbers from 0 to 99\n");
   for (i=0;i<10;i++)
      printf("%d\n",random(100));
}
