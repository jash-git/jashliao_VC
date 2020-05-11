
/*                            */
/*    Program Name: ldiv.c    */
/*                            */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *convert_string;
   long numer,denom;
   ldiv_t ldiv_result;
   printf("Enter the numerator and the denominator you want"
   " to evaluate\n");
   printf("Numerator:");
   scanf("%s",convert_string);
   numer=atol(convert_string);
   printf("Denominator:");
   scanf("%s",convert_string);
   denom=atol(convert_string);
   ldiv_result=ldiv(numer,denom);
   printf("Numerator/Denominator:%ld/%ld\n",numer,denom);
   printf("Quotient=%ld\nRemainder=%ld\n",ldiv_result.quot,
                                          ldiv_result.rem);
}
