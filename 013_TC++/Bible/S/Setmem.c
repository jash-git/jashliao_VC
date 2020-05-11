/*                              */
/*    Program Name: setmem.c    */
/*                              */
#include <mem.h>
#include <stdio.h>

void main( void )
{
   char Buffer[81];

   printf( "Before set:\n" );
   printf( "  Buffer = \"%s\".\n", Buffer );

   setmem( Buffer, 80, 'C' );
   Buffer[80] = '\0';

   printf( "After set:\n" );
   printf( "  Buffer = \"%s\".\n", Buffer );
}
