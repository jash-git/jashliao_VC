/*                                */
/*    Program Name: s_r_pale.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <process.h>
#include <stdio.h>

void main(void)
{
   int GraphDriver = VGA, GraphMode = VGAHI;
   int Height, i, j, MaxX;
   struct palettetype PaleInfo;

   if( registerbgidriver( EGAVGA_driver ) < 0 ) {~SD0.4

      printf( "EGAVGA driver registered failed!\a\n" );
      exit( 1 );
   }
   initgraph( &GraphDriver, &GraphMode, NULL );

   getpalette( &PaleInfo );

   Height = getmaxy() / 16;
   MaxX = getmaxx();

   /*  Setting gray scale of red.  */
   for( j = 0; j < PaleInfo.size; j++ )
      setrgbpalette( PaleInfo.colors[j], j*4, 0, 0 );
   /*  Draw a rectangle with red gray colors.  */
   for( i = 0 ; i < PaleInfo.size; i++ ) {
      setfillstyle( SOLID_FILL, i );
      bar( 0, i*Height, MaxX, ( i+1 )*Height-1 );
   }
   getch();

   /*  Setting gray scale of green.  */
   for( j = 0; j < PaleInfo.size; j++ )
      setrgbpalette( PaleInfo.colors[j], 0, j*4, 0 );
   getch();

   /*  Setting gray scale of blue.  */
   for( j = 0; j < PaleInfo.size; j++ )
      setrgbpalette( PaleInfo.colors[j], 0, 0, j*4 );
   getch();

   /*  Setting gray scale of white.  */
   for( j = 0; j < PaleInfo.size; j++ )
      setrgbpalette( PaleInfo.colors[j], j*4, j*4, j*4 );
   getch();

   closegraph();
}
