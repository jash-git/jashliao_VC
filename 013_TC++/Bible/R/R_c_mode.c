/*                                */
/*    Program Name: r_c_mode.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int ErrNo, CurrMode;
   char OutText[81];

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );
   ErrNo = graphresult();
   if( ErrNo != grOk ) {
      printf( "Error(%d): %s\n", ErrNo,
              grapherrormsg( ErrNo ) );
      exit( 1 );
   }

   /*  Save the current graphics mode.  */
   CurrMode = getgraphmode();

   sprintf( OutText, "Now we are in %s mode, press any key t\
o return text mode.", getmodename( GraphMode ) );
   outtextxy( 0, 0, OutText );
   getch();

   /*  Return to text mode.  */
   restorecrtmode();
   printf( "Now we are in text mode, press any key to return\
graphics mode." );
   getch();

   /*  Return to graphics mode.  */
   setgraphmode( CurrMode );
   outtextxy( 0, 0, "Now we are in graphics mode again!" );

   getch();
   closegraph();
}
