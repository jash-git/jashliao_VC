/*                               */
/*    Program Name: memccpy.c    */
/*                               */
#include <mem.h>
#include <stdio.h>

void main( void )
{
   char source[81], dest[81];

   printf( "Please input a string: " );
   gets( source );

   memccpy( dest, source, '\0', 81 );
   printf( "The destination string is \"%s\".\n", dest );
}
