/*                                */
/*    Program Name: s_a_pale.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int i, x, y, MaxX, MaxY;
   struct palettetype DefaPale, NewPale;
   char OutText[81];

   /*  Registered EGAVGA driver.  */
   if( registerbgidriver( EGAVGA_driver ) < 0 ) {
      printf( "EGAVGA driver registered failed!\a\n" );
      exit( 1 );
   }

   initgraph( &GraphDriver, &GraphMode, NULL );

   randomize();
   getpalette( &DefaPale );

   x = 0;
   y = 20;
   MaxX = getmaxx();
   MaxY = getmaxy();

   /*  Draw box.  */
   for( i = 0; i < 16; i++, x++ ) {
      if( x*70+50 > MaxX ) {
         x = 0;
         y += 70;
      }
      setfillstyle( SOLID_FILL, i );
      bar( x*70, y, x*70+50, y + 50 );
      sprintf( OutText, "COLOR %d", i );
      outtextxy( x*70, y+52, OutText );
   }
   outtextxy( 0, MaxY-30, "Default Palette. Hit any key to \
change all palette." );
   getch();

   /*  Change palette's color.  */
   NewPale.size = 16;
   NewPale.colors[0] = -1;
   for( i = 1; i < 16; i++ )
      NewPale.colors[i] = random( 64 );
   setallpalette( &NewPale );

   /*  Clear message.  */
   setviewport( 0, MaxY-30, MaxX, MaxY, 1 );
   clearviewport();
   setviewport( 0, 0, MaxX, MaxY, 1 );
   outtextxy( 0, MaxY-30, "New Palette. Hit any key to retu\
rn default palette." );
   getch();

   /*  Return to default palette.  */
   setallpalette( &DefaPale );

   /*  Clear message.  */
   setviewport( 0, MaxY-30, MaxX, MaxY, 1 );
   clearviewport();
   setviewport( 0, 0, MaxX, MaxY, 1 );
   outtextxy( 0, MaxY-30, "Default Palette again. Hit any k\
ey to EXIT." );
   getch();

   closegraph();
}
