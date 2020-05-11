/*                                */
/*    Program Name: g_a_rati.c    */
/*                                */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int Len = 160, xasp, yasp, Adjust;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   rectangle( 40, 40, 40+Len, 40+Len );
   outtextxy( 40, 50+Len, "Non-adjusted square" );

   getaspectratio( ( int far * )&xasp, ( int far * )&yasp );
   Adjust = ( long )Len * ( long )yasp / ( long )xasp;
   rectangle( 400, 40, 400+Adjust, 40+Len );
   outtextxy( 400, 50+Len, "Adjusted square" );

   getch();
   closegraph();
}
