/*                               */
/*    Program Name: heapchk.c    */
/*                               */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   int *Buf1, HeapMode;

   printf( "Allocate a memory...\n" );
   Buf1 = ( int * )calloc( 100, sizeof( int ) );
   Buf1 = ( int * )realloc( Buf1, 1024 );
   free( Buf1 );
   printf( "Free the memory.....\n" );

   HeapMode = heapcheck();

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