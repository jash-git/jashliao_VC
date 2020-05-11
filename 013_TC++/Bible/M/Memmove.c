/*                               */
/*    Program Name: memmove.c    */
/*                               */
#include <stdio.h>
#include <string.h>

void main( void )
{
   static char Buffer[80] = "C Bible";

   printf( "Before move:\n" );
   printf( "  Buffer = \"%s\".\n", Buffer );

   memmove( Buffer + 2, Buffer, sizeof( Buffer ) );

   printf( "After move:\n" );
   printf( "  Buffer = \"%s\".\n", Buffer );
}
