/*                         */
/*  Program Name: _rotl.c  */
/*                         */
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *convert_string;
   int shift;
   unsigned result, value;
   printf("Enter the value you want to rotated left how many bits\n");
   printf("Value:");
   scanf("%u", &value);
   printf("Bit(s):");
   scanf("%d", &shift);
   result = _rotl(value, shift);
   printf("The value %u rotated left %d bits = %u\n", value, shift, result);
}
