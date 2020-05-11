/*                                */
/*    Program Name: s_g_mode.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int MaxMode, i;
   char OutText[50];

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

   MaxMode = getmaxmode();

   for( i = 0; i <= MaxMode; i++ ) {
      setgraphmode( i );
      sprintf( OutText, "Mode: %s", getmodename( i ) );
      outtextxy( 0, 0, OutText );
      outtextxy( 0, 50, "Press any key to continue.." );
      getch();
   }

   closegraph();
}
