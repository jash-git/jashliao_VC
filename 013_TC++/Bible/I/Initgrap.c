/*                                */
/*    Program Name: initgrap.c    */
/*                                */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int ErrNo, i, y, TextHeight;
   int CHRname[] = { TRIPLEX_FONT, SMALL_FONT,
                     SANS_SERIF_FONT, GOTHIC_FONT };

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );
   ErrNo = graphresult();

   if( ErrNo != grOk ){
      printf( "Error(%d): %s\a\n", ErrNo,
              grapherrormsg( ErrNo ) );
      exit( 1 );
   }

   /*  Select the TRIPLEX, SMALL, SNAS_SERIF and GOTHIC
       fonts to display a string.  */
   for( i = 0, y = 0; i < 4; i++ ) {
      settextstyle( CHRname[i], HORIZ_DIR, 5 );
      TextHeight = textheight( "C" );
      outtextxy( 0, y, "C Bible" );
      y += TextHeight;
   }

   getch();
   closegraph();
}
