/*                                */
/*    Program Name: s_f_patt.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int MaxColor, MaxX, MaxY, Len, i, x, y;
   unsigned char Pattern[8];

   if( registerbgidriver( Herc_driver ) < 0 ) {
      printf( "HERC driver registered failed!\a\n" );
      exit( 1 );
   }
   if( registerbgidriver( CGA_driver ) < 0 ) {
      printf( "CGA driver registered failed!\a\n" );
      exit( 1 );
   }
   if( registerbgidriver( EGAVGA_driver ) < 0 ) {
      printf( "EGAVGA driver registered failed!\a\n" );
      exit( 1 );
   }

   initgraph( &GraphDriver, &GraphMode, NULL );
   MaxColor = getmaxcolor();
   MaxX = getmaxx();
   MaxY = getmaxy();

   randomize();

   do {
      for( i = 0; i < 8; i++ )
         Pattern[i] = random( 256 );
      setfillpattern( Pattern, random( MaxColor + 1 ) );
      x = random( MaxX );
      y = random( MaxY );
      Len = random( MaxY );
      bar( x, y, x+Len, y+Len );
   } while( !kbhit() );

   closegraph();
}
