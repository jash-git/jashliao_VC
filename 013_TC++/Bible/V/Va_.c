/*                            */
/*    Program Name : va_.c    */
/*                            */
#include <stdarg.h>
#include <stdio.h>

/*                             */
/*    Function Prototyping.    */
/*                             */
int Add( int, ... );

void main( void )
{
   printf( "1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = %d\n",
           Add( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -999 ) );
}

/*  The function "Add" will add the all arguments up.  */
int Add( int i, ... )
{
   int Sum = 0;
   va_list argp;

   /*  Initial the pointer - argp.  */
   va_start( argp, i );

   while( i != -999 ) {
      Sum += i;
      i = va_arg( argp, int );
   }
   va_end( argp );

   return( Sum );
}
