
/*                       */
/* Program Name: lfind.c */
/*                       */
#include <stdlib.h>
#include <stdio.h>

int intarr[]={999,17,15,122,143,144,200,199,395,578,466,11};

int compare(int *elem1,int *elem2)
{
   return(*elem1-*elem2);
}

void main(void)
{
   int inputint=0;
   int *ans=NULL;
   size_t NUM=12;
   printf("This is a game to test your luck.\n");
   printf("Please input one integer: ");
   scanf("%d",&inputint);
   ans=lfind(&inputint,intarr,&NUM,sizeof(int),compare);
   if (ans)
      printf("Bingo! %d is in the internal array.\n",
                                                  inputint);
   else
      printf("%d isn't in the internal array.\n",inputint);
}
