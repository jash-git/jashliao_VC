/*                                */
/*    Program Name: s_w_mode.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int CenterY, MaxX;

   /*  Graphics driver registered.  */
   if( registerbgidriver( Herc_driver ) < 0 ) {
      printf( "HERC driver registered failed!\a\n" );~SD0.4

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

   if( GraphDriver != EGA && GraphDriver != VGA ) {
      closegraph();
      printf( "Can't find EGA or VGA graphics card!\a\n" );
      exit( 1 );
   }

   CenterY = getmaxy() / 2;
   MaxX = getmaxx();
   setwritemode( COPY_PUT );
   setcolor( WHITE );
   line( 0, CenterY, MaxX, CenterY );
   outtextxy( 0, 0, "White line, hit any key.." );
   getch();

   setwritemode( XOR_PUT );
   setcolor( GREEN ^ WHITE );
   line( 0, CenterY, MaxX, CenterY );
   outtextxy( 0, 10, "Green line, hit any key.. " );
   getch();

   line( 0, CenterY, MaxX, CenterY );
   outtextxy( 0, 20, "Return to white line. Hit any key.."
            );

   getch();
   closegraph();
}
