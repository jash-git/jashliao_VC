
/*                         */
/* Program Name: strncmp.c */
/*                         */
#include <stdio.h>
#include <string.h>

void main(void)
{
   char *s1,*s2;
   size_t maxlen;
   int ptr;
   printf("Enter two string which you want to compare"
                                            " with\n");
   printf("First string: ");
   gets(s1);
   printf("Second string: ");
   gets(s2);
   printf("How many character your want to compare with: ");
   scanf("%d",&maxlen);
   ptr=strncmp(s1,s2,maxlen);
   if (ptr>0)
      printf("First string:%s is greater than Second"
                                  " string:%s",s1,s2);
   else if (ptr<0)
      printf("First string:%s is less than Second"
                               " string:%s",s1,s2);
   else
      printf("First string:%s is the same as Second"
                                 " string:%s",s1,s2);
}
