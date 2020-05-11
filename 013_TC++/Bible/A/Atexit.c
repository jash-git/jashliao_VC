/*                              */
/*    Program Name: atexit.c    */
/*                              */
#include <stdio.h>
#include <stdlib.h>

/*                             */
/*    Function Prototyping.    */
/*                             */
void Fun1( void );
void Fun2( void );
void Fun3( void );
void Fun4( void );
void Fun5( void );
void Fun6( void );

void main( void )
{
   printf( "\nNow recording Function 1..\n" );
   atexit( Fun1 );
   printf( "Now recording Function 2..\n" );
   atexit( Fun2 );
   printf( "Now recording Function 3..\n" );
   atexit( Fun3 );
   printf( "Now recording Function 4..\n" );
   atexit( Fun4 );
   printf( "Now recording Function 5..\n" );
   atexit( Fun5 );
   printf( "Now recording Function 6..\n" );
   atexit( Fun6 );

   printf( "The main program is stop!\n" );
}

/*  Function 1.  */
void Fun1( void )
{
   printf( "Function 1 is called.\n" );
}

/*  Function 2.  */
void Fun2( void )
{
   printf( "Function 2 is called.\n" );
}

/*  Function 3.  */
void Fun3( void )
{
   printf( "Function 3 is called.\n" );
}

/*  Function 4.  */
void Fun4( void )
{
   printf( "Function 4 is called.\n" );
}

/*  Function 5.  */
void Fun5( void )
{
   printf( "Function 5 is called.\n" );
}

/*  Function 6.  */
void Fun6( void )
{
   printf( "Function 6 is called.\n" );
}
