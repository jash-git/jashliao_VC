/*                                */
/*    Program Name: fheapchk.c    */
/*                                */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   int far *Buf1, HeapMode;

   printf( "Allocate a memory...\n" );
   Buf1 = ( int far * )farcalloc( 100, sizeof( int ) );
   Buf1 = ( int far * )farrealloc( Buf1, 1024 );
   farfree( Buf1 );
   printf( "Free the memory.....\n" );

   HeapMode = farheapcheck();

   switch( HeapMode ) {
      case _HEAPOK      : printf( "Heap is OK!\n" );
                          break;
      case _HEAPEMPTY   : printf( "No heap!\n" );
                          break;
      case _HEAPCORRUPT : printf( "Heap is destroyed!\n" );
                          break;
   }
}
