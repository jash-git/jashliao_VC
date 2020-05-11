/*                              */
/*    Program Name: setjmp.c    */
/*                              */
#include <stdio.h>
#include <setjmp.h>

jmp_buf RetBuff;

/*                             */
/*    Function Prototyping.    */
/*                             */
void Return( int );

void main( void )
{
   int RetValue;
   int Var;

   /*  Setting the local variable Var's content.  */
   Var = 10;
   printf( "Var = 10\n" );

   printf( "Set up return status by calling the " );
   printf( "function \"setjmp\"..\n" );
   RetValue = setjmp( RetBuff );

   if( RetValue ) {
      printf( "Return by call the function " );
      printf( "\"longjmp\".\n" );
      printf( "Var recover its old content -> %d.\n", Var );
      exit( 0 );
   }

   Var = 100;
   printf( "The Var new value is %d.\n", Var );
   printf( "Now calling the function \"longjmp\"..\n" );
   Return( RetValue );
}

/*  Function "Return" will call "longjmp".  */
void Return( int RetValue )
{
   longjmp( RetBuff, RetValue );
}
