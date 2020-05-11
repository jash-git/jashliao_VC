
/*                     */
/* Program Name: min.c */
/*                     */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *convert_string1,*convert_string2;
   double x,y,min_val;
   printf("Enter two value to find smaller value\n");
   printf("\nValue one:");
   scanf("%s",convert_string1);
   printf("Value two:");
   scanf("%s",convert_string2);
   x=atof(convert_string1);
   y=atof(convert_string2);
   min_val=min(x,y);
   printf("Smaller value of %g and %g is %g\n",x,y,min_val);
}
