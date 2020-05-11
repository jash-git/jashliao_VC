
/*                          */
/* Program Name: _strtold.c */
/*                          */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *convert_string,*stop_at;
   double convert_value;
   printf("Enter an integer:");
   scanf("%s",convert_string);
   convert_value=_strtold(convert_string,&stop_at);
   printf("You enter value = %g\n",convert_value);
   printf("After converting, stopped at: %s\n",stop_at);
}

