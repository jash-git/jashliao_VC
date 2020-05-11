/*                                */
/*    Program Name: r_b_driv.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int ErrNo;

   /*  Register the EGAVGA driver.  */
   ErrNo = registerbgidriver( EGAVGA_driver );
   if( ErrNo < 0 ) {
      printf( "EGAVGA driver registered failure!\a\n" );
      exit( 1 );
   }

   /*  Register the HERC driver.  */
   ErrNo = registerbgidriver( Herc_driver );
   if( ErrNo < 0 ) {
      printf( "HERC driver registered failure!\a\n" );
      exit( 1 );
   }

   /*  Register the TRIP font.  */
   ErrNo = registerfarbgifont( triplex_font_far );
   if( ErrNo < 0 ) {
      printf( "TRIP font registered failure!\a\n" );
      exit( 1 );
   }

   initgraph( &GraphDriver, &GraphMode, NULL );
   ErrNo = graphresult();
   if( ErrNo != grOk ) {
      printf( "Error(%d): %s\n", ErrNo,
              grapherrormsg( ErrNo ) );
      exit( 1 );
   }

   settextstyle( TRIPLEX_FONT, HORIZ_DIR, 2 );
   outtextxy( 0, 0, "The EGAVGA & HERC driver registered in \
the program." );
   outtextxy( 0, textheight( "T" ), "So you can run this pro\
gram without drivers." );
   getch();
   closegraph();
}
