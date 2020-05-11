/*                               */
/*    Program Name: getcolor.c   */
/*                               */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int OldColor;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   OldColor = getcolor();
   setcolor( 12 );
   rectangle( 50, 50, 100, 100 );
   outtextxy( 50, 110, "New color" );

   setcolor( OldColor );
   rectangle( 200, 50, 250, 100 );
   outtextxy( 200, 110, "Old color" );

   getch();
   closegraph();
}
