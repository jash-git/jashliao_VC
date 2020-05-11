
/*                       */
/* Program Name: pow10.c */
/*                       */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>    /* errno is defined here */

void main(void)
{
   char *convert_string;
   int p;
   double pow10_val;
   printf("Enter two number that you want to evaluate"
   " its 10^p\n");
   printf("P:");
   scanf("%s",convert_string);
   p=atoi(convert_string);
   pow10_val=pow10(p);
   printf("Ten raised to %d is %g\n",p,pow10_val);
}
