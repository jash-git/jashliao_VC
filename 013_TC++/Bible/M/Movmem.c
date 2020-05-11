/*                              */
/*    Program Name: movmem.c    */
/*                              */
#include <mem.h>
#include <stdio.h>

void main( void )
{
   static char Buffer[80] = "C Bible";

   printf( "Before move:\n" );
   printf( "  Buffer = \"%s\".\n", Buffer );

   movmem( Buffer, Buffer + 2, sizeof( Buffer ) );

   printf( "After move:\n" );
   printf( "  Buffer = \"%s\".\n", Buffer );
}
