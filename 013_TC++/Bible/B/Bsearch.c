
/*                         */
/* Program Name: bsearch.c */
/*                         */
#include <stdlib.h>
#include <stdio.h>

#define NUM(arr) sizeof(arr)/sizeof(arr[0])

int intarr[]={11,15,17,122,143,144,199,200,395,466,578,999};

int compare(const int *elem1, const int *elem2)
{
   return(*elem1-*elem2);
}

int check(int key)
{
   int *ans;
   ans=bsearch(&key,intarr,NUM(intarr),sizeof(int),compare);
   return (ans!=NULL);
}

void main(void)
{
   int inputint=0;
   printf("This is a game to test your luck.\n");
   printf("Please input one integer: ");
   scanf("%d",&inputint);
   if (check(inputint))
      printf("Bingo! %d is in the internal array.\n",
                                                  inputint);
   else
      printf("%d isn't in the internal array.\n",inputint);
}
