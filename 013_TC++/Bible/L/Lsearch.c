
/*                         */
/* Program Name: lsearch.c */
/*                         */
#include <stdlib.h>
#include <stdio.h>

int intarr[]={999,17,15,122,143,144,200,199,395,578,466,11};

int compare(int *elem1,int *elem2)
{
   return(*elem1-*elem2);
}

void main(void)
{
   int inputint=0,i,intarrlong;
   int *ans=NULL;
   size_t NUM=12;
   intarrlong=sizeof(intarr);
   for (i=1;i<=2;i++) {
      printf("This is a game to test your luck.\n");
      printf("Please input one integer: ");
      scanf("%d",&inputint);
      ans=lsearch(&inputint,intarr,&NUM,sizeof(int),compare)
      ;
      if (ans<intarr+intarrlong/2) {
         printf("Bingo! %d is in the internal array.\n",
                                                  inputint);
         i++;
      }
      else {
         printf("%d isn't in the internal array.\n",
                                                  inputint);
         printf("Your integer number already insert into"
                                 " internal array.\n");
         intarrlong+=2;
         if (i<2)
            printf("Try again!\n");
      }
   }
}
