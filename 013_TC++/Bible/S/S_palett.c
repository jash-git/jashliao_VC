/*                                */
/*    Program Name: s_palett.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int i;
   struct palettetype PaleInfo;

   /*  Graphics driver registered.  */
   if( registerbgidriver( EGAVGA_driver ) < 0 ) {
      printf( "EGAVGA driver registered failed!\a\n" );
      exit( 1 );
   }
   initgraph( &GraphDriver, &GraphMode, NULL );

   getpalette( &PaleInfo );
   circle( getmaxx()/2, getmaxy()/2, 100 );
   outtextxy( 0, 0, "Press any key to change color.." );
   getch();
   for( i = 14; i ; i-- ) {
      setpalette( 15, PaleInfo.colors[i] );
      getch();
   }

   closegraph();
}
