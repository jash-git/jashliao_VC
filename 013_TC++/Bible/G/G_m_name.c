/*                                */
/*    Program Name: g_m_name.c    */
/*                                */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   char OutText[81];

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   sprintf( OutText, "You are in %s mode.",
            getmodename( GraphMode ) );
   outtextxy( 0, 0, OutText );
   getch();
   closegraph();
}
