/*                                */
/*    Program Name: setcolor.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int MaxColor, CenterX, CenterY, Color;
   char OutText[10];

   /*  Register graphics drivers.  */
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
   CenterX = getmaxx() / 2;
   CenterY = getmaxy() / 2;

   randomize();

   do {
      clearviewport();
      Color = random( MaxColor+1 );
      setcolor( Color );
      circle( 100, 100, 80 );
      sprintf( OutText, "COLOR %d", Color );
      outtextxy( 80, 170, OutText );
      outtextxy( CenterX-155, CenterY, "Press <Enter> to EX\
IT, another key to switch color.." );
   } while( getch() != 13 );

   closegraph();
}
