/*                                */
/*    Program Name: s_a_page.c    */
/*                                */
#include <alloc.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int MaxX, MaxY, EndY, StartY, i, j;
   char *Image;

   /*  Registered the drivers and font.  */
   if( registerbgidriver( Herc_driver ) < 0 ) {
      printf( "HERC driver registered failed!\a\n" );
      exit( 1 );
   }
   if( registerbgidriver( EGAVGA_driver ) < 0 ) {
      printf( "EGAVGA driver register failed!\a\n" );
      exit( 1 );
   }
   if( registerfarbgifont( gothic_font_far ) < 0 ) {
      printf( "GOTHIC font registered failed!\a\n" );
      exit( 1 );
   }

   initgraph( &GraphDriver, &GraphMode, NULL );

   MaxX = getmaxx();
   MaxY = getmaxy();
   Image = ( char * )malloc( imagesize( 0, 0, MaxX, MaxY )
           );

   /*  Set active & visual page, and display a string
       in active page.  */
   setactivepage( 1 );
   setvisualpage( 0 );
   settextstyle( GOTHIC_FONT, HORIZ_DIR, 15 );
   outtextxy( MaxX/2-200, MaxY/2-90, "C Bible" );

   /*  Calculate the top line and the bottom line of
       the text.  */
   StartY = MaxY / 2 - 50;
   EndY = StartY + textheight( "C" ) - 40;

   /*  Special Display.  */
   for( i = EndY; i >= StartY; i-- ) {
      getimage( 0, i, MaxX, i, Image );
      setactivepage( 0 );
      for( j = 0; j <= i; j++ )
         putimage( 0, j, Image, COPY_PUT );
      setactivepage( 1 );
   }

   getch();
   closegraph();
}
