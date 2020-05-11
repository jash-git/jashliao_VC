/*                              */
/*    Program Name: assert.c    */
/*                              */
#include <assert.h>
#include <stdio.h>

void main( void )
{
   int x, y;

   printf( "Please input two integer for division: " );
   scanf( "%d %d", &x, &y );

   /*  Is the divisor zero?  */
   assert( y != 0 );

   /*  Print the result.  */
   printf( "%d / %d = %d.\n", x, y, x/y );
}
