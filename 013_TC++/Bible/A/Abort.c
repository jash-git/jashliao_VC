/*                             */
/*    Program Name: abort.c    */
/*                             */
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   int x, y;

   printf( "Please input two integer for division: " );
   scanf( "%d %d", &x, &y );

   /*  Is the divisor zero?  */
   if( !y ) {
      printf( "Sorry, the divisor can't be ZERO!\a\n" );
      abort();
   }

   /*  Print the result.  */
   printf( "%d / %d = %d\n", x, y, x/y );
}
