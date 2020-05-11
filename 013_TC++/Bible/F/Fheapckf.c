/*                                */
/*    Program Name: fheapckf.c    */
/*                                */
#include <alloc.h>
#include <stdio.h>

void ShowStatus( int );

void main( void )
{
   char far *Buf;
   int  HeapMode;

   printf( "Allocating the memory...\n" );
   Buf = ( char far * )farcalloc( 100, sizeof( char ) );

   printf( "Fill the free memory blocks in the heap with \
\'C\'.\n" );
   ShowStatus( farheapfillfree( 'C' ) );

   farfree( Buf );
   printf( "Freeing the memory...\n" );
   ShowStatus( farheapcheckfree( 'C' ) );
}

void ShowStatus( int HeapStatus )
{
   switch( HeapStatus ) {
      case _HEAPOK      : printf( "Heap is OK!\n" );
                          break;
      case _HEAPEMPTY   : printf( "No heap!\n" );
                          break;
      case _HEAPCORRUPT : printf( "Heap is destroyed!\n" );
                          break;
      case _BADVALUE    : printf( "Found another char in th\
e heap!\n" );
                          break;
   }
}
