/*                              */
/*    Program Name: putenv.c    */
/*                              */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main( int argc, char *argv[] )
{
   char *Env;

   if( argc != 2 ) {
      printf( "Usage: PUTENV environment-variable=" );
      printf( "definition\n" );
      abort();
   }

   strupr( argv[1] );

   if( putenv( argv[1] ) == -1 )
      printf( "Add environment variable [%s] failure!\n",
              argv[1] );
   else
   {
      Env = strtok( argv[1], "=" );
      printf( "New environment variable [" );
      printf( "%s=%s]\n", Env, getenv( Env ) );
   }
}
