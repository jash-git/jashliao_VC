/*                                */
/*    Program Name: s_v_port.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   char OutText[50];

   /*  Graphics drivers registered.  */
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

   outtextxy( 0, 0, "*(0, 0)<--The default view port left-to\
p corner." );
   setviewport( 20, 20, getmaxx()-20, getmaxy()-20, 1 );
   outtextxy( 0, 0, "*(20, 20)<--The new view port left-top\
 corner." );

   getch();
   closegraph();
}
