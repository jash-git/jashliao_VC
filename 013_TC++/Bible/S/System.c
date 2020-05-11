/*                              */
/*    Program Name: system.c    */
/*                              */
#include <stdio.h>
#include <stdlib.h>

void main( int argc, char *argv[] )
{
   if( argc != 2 ) {
      printf( "Usage: SYSTEM command\n" );
      abort();
   }

   if( system( argv[1] ) == -1 )
      printf( "Command error!\a\n" );

}
