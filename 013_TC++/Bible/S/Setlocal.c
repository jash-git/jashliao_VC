/*                                */
/*    Program Name: setlocal.c    */
/*                                */
#include <locale.h>
#include <stdio.h>

void main( void )
{
   printf( "Old locale was %s\n", setlocale( LC_MONETARY,
           "C" ) );
}
