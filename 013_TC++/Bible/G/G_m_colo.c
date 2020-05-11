/*                                */
/*    Program Name: g_m_colo.c    */
/*                                */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int MaxColor, MaxX, i, x, y;
   char OutText[50];

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   MaxColor = getmaxcolor();
   MaxX = getmaxx();

   y = 50;
   for( x = i = 0; i <= MaxColor; i++, x++ ) {
      setfillstyle( SOLID_FILL, i );
      if( 70+x*80 > MaxX ) {
         x = 0;
         y = y + 80;
      }
      sprintf( OutText, "Color %d", i );
      bar( 10+x*80, y, 70+x*80, y+50 );
      outtextxy( 10+x*80, y+52, OutText );
   }

   getch();
   closegraph();
}
