/*                             */
/*    Program Name: raise.c    */
/*                             */
#include <signal.h>
#include <stdio.h>

void main( void )
{
   printf( "Raise the signal SIGINT..\n" );
   raise( SIGINT );
}
