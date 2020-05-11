/*                                */
/*    Program Name: s_f_styl.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   struct fillsettingstype Pattern;
   int GraphDriver = DETECT, GraphMode;
   int MaxColor, MaxX, MaxY, x, y;

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

   randomize();

   MaxColor = getmaxcolor();
   MaxX = getmaxx();
   MaxY = getmaxy();

   do {
      x = random( MaxX );
      y = random( MaxY );
      setfillstyle( random( 12 ), random( MaxColor + 1 ) );
      bar( x, y, x+50, y+50 );
   } while( !kbhit() );

   closegraph();
}
