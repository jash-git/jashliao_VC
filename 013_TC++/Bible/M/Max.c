
/*                     */
/* Program Name: max.c */
/*                     */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *convert_string1,*convert_string2;
   double x,y,max_val;
   printf("Enter two value to find larger value\n");
   printf("\nValue one:");
   scanf("%s",convert_string1);
   printf("Value two:");
   scanf("%s",convert_string2);
   x=atof(convert_string1);
   y=atof(convert_string2);
   max_val=max(x,y);
   printf("Larger value of %g and %g is %g\n",x,y,max_val);
}
