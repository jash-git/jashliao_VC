
/*                       */
/* Program Name: qsort.c */
/*                       */
#include <stdlib.h>
#include <stdio.h>

int intarr[]={999,15,17,143,122,144,578,200,395,466,333,11};

int compare(const int *elem1, const int *elem2)
{
   return(*elem1-*elem2);
}

void main(void)
{
   int i;
   printf("Source sequence: ");
   for (i=0;i<=11;i++)
      printf("%d\n",intarr[i]);
   qsort((void *)intarr,12,sizeof(intarr[0]),compare);
   printf("\nSorting...\n\n");
   printf("Target sequence: ");
   for (i=0;i<=11;i++)
      printf("%d\n",intarr[i]);
}
