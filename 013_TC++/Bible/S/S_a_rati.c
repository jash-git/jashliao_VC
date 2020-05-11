/*                                */
/*    Program Name: s_a_pati.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int xasp, yasp;
   char OutText[81];

   printf( "Please input new aspect ratio: " );
   scanf( "%d %d", &xasp, &yasp );

   if( registerbgidriver( Herc_driver ) < 0 ) {
      printf( "HERC driver registered failed!\a\n" );
      exit( 1 );
   }
   if( registerbgidriver( EGAVGA_driver ) < 0 ) {
      printf( "EGAVGA driver registered failed!\a\n" );
      exit( 1 );
   }

   initgraph( &GraphDriver, &GraphMode, NULL );

   sprintf( OutText, "Aspect ratio x is %d", xasp );
   outtextxy( 0, 0, OutText );
   sprintf( OutText, "             y is %d", yasp );
   outtextxy( 0, 10, OutText );
   outtextxy( 0, 20, "In this ratio, the circle will look:"
            );
   setaspectratio( xasp, yasp );
   circle( 150, 150, 100 );
   getch();
   closegraph();
}
