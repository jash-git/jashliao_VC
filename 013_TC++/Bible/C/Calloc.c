/*                               */
/*    Program Name : calloc.c    */
/*                               */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   char *Buff;

   /*  Buffer allocated.  */
   Buff = calloc( 80, sizeof( char ) );

   printf( "Buffer allocated.\n" );
   printf( "Please input a string : " );
   gets( Buff );
   printf( "The string you input is : \"%s\".\n", Buff );
}
