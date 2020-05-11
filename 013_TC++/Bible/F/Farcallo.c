/*                                 */
/*    Program Name : farcallo.c    */
/*                                 */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   char far *BigMem;

   BigMem = farcalloc( 100000l, sizeof( char ) );
   if( BigMem == NULL ) {
      printf( "Can't allocated memory!\n" );
      abort();
   }
   printf( "Allocated the array of 100000 characters" );
   printf( " at %Fp.\n", BigMem );
}
