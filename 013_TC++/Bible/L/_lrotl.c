/*                          */
/*  Program Name: _lrotl.c  */
/*                          */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *convert_string;
   int shift;
   unsigned long result, value;
   printf("Enter the value you want to rotated left how many bits\n");
   printf("Value: ");
   scanf("%lu", &value);
   printf("Bit(s):");
   scanf("%d", &shift);
   result = _lrotl(value, shift);
   printf("The value %lu rotated left %d bits = %lu\n", value, shift, result);
}
