/*                                */
/*    Program Name: heapchkn.c    */
/*                                */
#include <alloc.h>
#include <stdio.h>

void ShowStatus( int );

void main( void )
{
   int *Buf;

   printf( "Before allocate the memory, the Buf is " );
   ShowStatus( heapchecknode( ( int * )Buf ) );

   printf( "After allocate the memory, the Buf is " );
   Buf = ( int * )calloc( 100, sizeof( int ) );
   ShowStatus( heapchecknode( ( int * )Buf ) );

   printf( "Free the memory, the Buf is " );
   free( Buf );
   ShowStatus( heapchecknode( ( int * )Buf ) );
}

void ShowStatus( int HeapStatus )
{
   switch( HeapStatus ) {
      case _HEAPEMPTY   : printf( "EMPTY!\n" );
                          break;
      case _FREEENTRY   : printf( "FREE!\n" );
                          break;
      case _USEDENTRY   : printf( "USED!\n" );
                          break;
      case _HEAPCORRUPT : printf( "DESTROYED!\n" );
                          break;
      case _BADNODE     : printf( "BAD NODE!\n" );
                          break;
   }
}
