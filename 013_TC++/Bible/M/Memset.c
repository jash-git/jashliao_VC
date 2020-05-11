/*                        */
/* Program Name: memset.c */
/*                        */
#include <mem.h>
#include <stdio.h>

void main( void )
{
   char Buffer[81];

   printf( "Before set:\n" );
   printf( "  Buffer = \"%s\".\n", Buffer );

   memset( Buffer, 'C', 80 );
   Buffer[80] = '\0';

   printf( "After set:\n" );
   printf( "  Buffer = \"%s\".\n", Buffer );
}
