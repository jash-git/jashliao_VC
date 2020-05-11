/*                            */
/*    Program Name: gety.c    */
/*                            */
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int PosX, PosY;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   randomize();

   do {
      moveto( random( getmaxx() ), random( getmaxy() ) );
      PosX = getx();
      PosY = gety();
      lineto( random( getmaxx() ), random( getmaxy() ) );
      lineto( random( getmaxx() ), random( getmaxy() ) );
      lineto( PosX, PosY );
      delay( 50 );
      clearviewport();
   } while( !kbhit() );

   getch();
   closegraph();
}
