
/*                     */
/* Program Name: div.c */
/*                     */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *convert_string;
   int numer, denom;
   div_t div_result;
   printf("Enter the numerator and the denominator you want"
   " to evaluate\n");
   printf("Numerator:");
   scanf("%s",convert_string);
   numer=atoi(convert_string);
   printf("Denominator:");
   scanf("%s",convert_string);
   denom=atoi(convert_string);
   div_result=div(numer,denom);
   printf("Numerator/Denominator:%d/%d\n",numer,denom);
   printf("Quotient=%d\nRemainder=%d\n",div_result.quot,
                                         div_result.rem);
}
