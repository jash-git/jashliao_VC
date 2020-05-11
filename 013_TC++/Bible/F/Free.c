/*                            */
/*    Program Name: free.c    */
/*                            */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   char *MemBlk;

   if( ( MemBlk = ( char * )malloc( 256 ) ) == NULL ) {
      printf( "Memory allocated failed!\a\n" );
      abort();
   }
   printf( "Memory allocated!\n" );

   printf( "Please input a string: " );
   gets( MemBlk );
   printf( "This string is \"%s\".\n", MemBlk );

   free( MemBlk );
   printf( "Memory deallocated!\n" );
}
