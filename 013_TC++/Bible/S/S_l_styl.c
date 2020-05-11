/*                                */
/*    Program Name: s_l_styl.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int MaxX, MaxY, x, y, i;
   /*  Pattern: þþþþþþ  þþ  þþ  .  */
   unsigned LinePatt = 64716;

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
   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   MaxX = getmaxx();
   MaxY = getmaxy();

   for( x=0, y =0, i = 0; i < 5; i++ ) {
      x = i * 10;
      y = x;
      setlinestyle( i, LinePatt, 1 );
      rectangle( x, y, MaxX - x, MaxY - y );
   }

   getch();
   closegraph();
}
