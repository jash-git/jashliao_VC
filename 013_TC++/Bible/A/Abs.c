
/*                     */
/* Program Name: abs.c */
/*                     */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   int num, abs_num;
   printf("Please input an integer number:");
   scanf("%d",&num);
   abs_num=abs(num);
   printf("Number:%d\nAbsolute value:%d\n",num,abs_num);
}
