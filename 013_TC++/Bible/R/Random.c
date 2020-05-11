
/*                        */
/* Program Name: random.c */
/*                        */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   int i,randnum;
   printf("Ten random numbers in the 0-99 range:\n");
   for (i=0;i<10;i++)
      printf("%d\n",random(100));
}
