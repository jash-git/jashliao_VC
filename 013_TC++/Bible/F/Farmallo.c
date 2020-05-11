/*                                */
/*    Program Name: farmallo.c    */
/*                                */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   char far *BigMem;

   if( ( BigMem = farmalloc( 100000l ) ) == NULL ) {
      printf( "Allocated memory failed!\a\n" );
      abort();
   }

   printf( "Allocated 100000 bytes memory at %Fp.\n",
           BigMem );
}
