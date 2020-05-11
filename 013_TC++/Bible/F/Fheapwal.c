/*                                */
/*    Program Name: fheapwal.c    */
/*                                */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   char far *Buf1, far *Buf2;
   struct farheapinfo HeapStatus;

   Buf1 = ( char far * )farcalloc( 100, sizeof( char ) );
   Buf2 = ( char far * )farmalloc( 512 );
   farfree( Buf1 );

   printf( "Heap Address   Heap Size   Heap Mode\n" );
   printf( "------------------------------------\n" );
   HeapStatus.ptr = NULL;
   while( farheapwalk( &HeapStatus ) == _HEAPOK ) {
      printf( " %Fp        %lu        ", HeapStatus.ptr,
              HeapStatus.size );
      ( HeapStatus.in_use ) ? printf( " USED\n" ) :
                              printf( " FREE\n" );
   }
   printf( "------------------------------------\n" );

   farfree( Buf2 );
}
