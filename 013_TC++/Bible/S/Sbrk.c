/*                             */
/*    Program Name : sbrk.c    */
/*                             */
#include <alloc.h>
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   char *Buff;

   /*  Allocate the buffer.  */
   if( ( Buff = sbrk( 255 ) ) == ( char * )-1 ) {
      printf( "Altering the break value failed.\n" );
      abort();
   }


   printf( "Buffer allocated.\n" );
   printf( "Please input a string: " );
   gets( Buff );
   printf( "The string is \"%s\".\n", Buff );
   sbrk( -255 );
   printf( "The buffer deallocated!\n" );
}
