/*                            */
/*    Program Name: swab.c    */
/*                            */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main( void )
{
   char Buffer1[81], Buffer2[81];
   int Len;

   printf( "Please input a string: " );
   gets( Buffer1 );

   /*  The length of Buffer1 must be even.  */
   Len = 2 * ( strlen( Buffer1 ) / 2 );
   Buffer1[Len] = '\0';
   Buffer2[Len] = '\0';

   swab( Buffer1, Buffer2, Len );
   printf( "After copy and swap by called swab, the " );
   printf( "string = \"%s\".\n", Buffer2 );
}
