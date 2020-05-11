/*                              */
/*    Program Name: signal.c    */
/*                              */
#include <signal.h>
#include <stdio.h>

/*                             */
/*    Function Prototyping.    */
/*                             */
void SIGFPE_Handler( int );

void main( void )
{
   int a, b;

   if( signal( SIGFPE, SIGFPE_Handler ) == SIG_ERR ) {
      perror( "Set up signal handler error!" );
      abort();
   }

   printf( "If you divided some integer by 0, it can " );
   printf( "start \nthe signal handler..\n" );
   printf( "Now we can input two integers for division.\n" );
   scanf( "%d %d", &a, &b );
   printf( "%d / %d = %d\n", a, b, a/b );
}

/*  The handler for floating-point error.  */
void SIGFPE_Handler( int signum )
{
   printf( "Signal: %d\n", signum );
   perror( "Division error!\a" );
   abort();
}
