/*                          */
/*  Program Name: _ctr87.c  */
/*                          */
#include <stdio.h>
#include <float.h>

void main(void)
{
   double a = 0.1;
   /* Read current floating point control word */
   printf("Current control word = %.4X\n", _control87(0, 0));
   /* Now lower the precision to 24 bits */
   _control87(PC_24, MCW_PC);
   /* Perform a math operation and see the result */
   printf("0.1x0.1=0.01 in 24 bit precision = %.15e\n", a*a);
   /* Restore precision to default 64 bits and redo */
   _control87(CW_DEFAULT, 0xfffff);
   printf("0.1x0.1=0.01 in 64 bit precision = %.15e\n", a*a);
}
