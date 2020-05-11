/*                              */
/*    Program Name: memcmp.c    */
/*                              */
#include <mem.h>
#include <stdio.h>

void main( void )
{
   char Buffer1[] = "C BIBLE", Buffer2[] = "C Bible";
   int RetValue;

   printf( "First string is \"%s\".\n", Buffer1 );
   printf( "Second string is \"%s\".\n", Buffer2 );

   RetValue = memcmp( Buffer1, Buffer2, 7 );

   if( !RetValue )
      printf( "First string = Second string.\n" );
   else
      if( RetValue < 0 )
         printf( "First string < Second string,\n" );
      else
         printf( "First string > Second string.\n" );
}
