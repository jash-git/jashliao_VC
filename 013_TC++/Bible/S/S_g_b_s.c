/*                               */
/*    Program Name: s_g_b_s.c    */
/*                               */
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int CurrBufSize;

   CurrBufSize = setgraphbufsize( 0 );
   printf( "The default graphics buffer size is %d bytes.\n"
          , CurrBufSize );
   setgraphbufsize( CurrBufSize );
}
