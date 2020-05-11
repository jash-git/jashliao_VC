/*                               */
/*    Program Name: farfree.c    */
/*                               */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   char far *BigMem;
   unsigned long NumBytes;

   printf( "There are %lu bytes free in memory.\n",
           farcoreleft() );

   printf( "How many bytes do you want to allocated: " );
   scanf( "%lu", &NumBytes );

   if( ( BigMem = farmalloc( NumBytes ) ) == NULL ) {
      printf( "Allocated memory failed!\a\n" );
      abort();
   }

   printf( "Allocated %lu bytes memory at %Fp.\n",
           NumBytes, BigMem );
   printf( "So we only have %lu bytes in memory.\n",
           farcoreleft() );

   farfree( BigMem );
   printf( "Free the allocated memory!\n" );
   printf( "Now, we have %lu bytes memory again.\n",
           farcoreleft() );
}
