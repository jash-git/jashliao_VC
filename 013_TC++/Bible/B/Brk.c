/*                            */
/*    Program Name : brk.c    */
/*                            */
#include <alloc.h>
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   char *Buff;

   /*  Get the current break value.  */
   if( ( Buff = sbrk( 0 ) ) == ( char * )-1 ) {
      printf( "Can't get the current break value.\n" );
      abort();
   }

   /*  Allocate the buffer.  */
   if( brk( Buff + 255 ) == -1 ) {
      printf( "Altering the break value failed.\n" );
      abort();
   }

   printf( "Buffer allocated.\n" );
   printf( "Please input a string: " );
   gets( Buff );
   printf( "The string is \"%s\".\n", Buff );
   brk( Buff - 255 );
   printf( "The buffer deallocated!\n" );
}
