/*                                */
/*    Program Name: heapwalk.c    */
/*                                */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   char *Buf1, *Buf2;
   struct heapinfo HeapStatus;

   Buf1 = ( char * )calloc( 100, sizeof( char ) );
   Buf2 = ( char * )malloc( 512 );
   free( Buf1 );

   printf( "Heap Address   Heap Size   Heap Mode\n" );
   printf( "------------------------------------\n" );
   HeapStatus.ptr = NULL;
   while( heapwalk( &HeapStatus ) == _HEAPOK ) {
      printf( "   %p          %u         ", HeapStatus.ptr,
              HeapStatus.size );
      ( HeapStatus.in_use ) ? printf( "USED\n" ) :
                              printf( "FREE\n" );
   }
   printf( "------------------------------------\n" );

   free( Buf2 );
}
