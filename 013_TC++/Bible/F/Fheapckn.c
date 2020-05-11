/*                                */
/*    Program Name: fheapckn.c    */
/*                                */
#include <alloc.h>
#include <stdio.h>

void ShowStatus( int );

void main( void )
{
   int far *Buf;

   printf( "Before allocate the memory, the Buf is " );
   ShowStatus( farheapchecknode( ( int far * )Buf ) );

   printf( "After allocate the memory, the Buf is " );
   Buf = ( int far * )farcalloc( 100, sizeof( int ) );
   ShowStatus( farheapchecknode( ( int far * )Buf ) );

   printf( "Free the memory, the Buf is " );
   farfree( Buf );
   ShowStatus( farheapchecknode( ( int far * )Buf ) );
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