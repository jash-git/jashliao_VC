/*                               */
/*    Program Name: heapflf.c    */
/*                               */
#include <alloc.h>
#include <stdio.h>

void ShowStatus( int );

void main( void )
{
   char *Buf;
   int  HeapMode;

   printf( "Allocating the memory...\n" );
   Buf = ( char * )calloc( 100, sizeof( char ) );

   printf( "Fill the free memory blocks in the heap with \
\'C\'.\n" );
   ShowStatus( heapfillfree( 'C' ) );

   free( Buf );
   printf( "Freeing the memory...\n" );
   ShowStatus( heapcheckfree( 'C' ) );
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