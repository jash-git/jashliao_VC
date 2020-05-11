/*                                */
/*    Program Name: g_v_sett.c    */
/*                                */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   struct viewporttype ViewPortInfo;
   char OutText[81];

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   getviewsettings( &ViewPortInfo );
   outtextxy( 0, 0, "Current viewport coordinate: " );
   sprintf( OutText, "Top-Left corner: (%d,%d).",
            ViewPortInfo.left, ViewPortInfo.top );
   outtextxy( 48, 10, OutText );
   sprintf( OutText, "Bottom-Right corner: (%d,%d).",
            ViewPortInfo.right, ViewPortInfo.bottom );
   outtextxy( 16, 20, OutText );
   if( ViewPortInfo.clip )
      outtextxy( 16, 30, "Clip ON." );
   else
      outtextxy( 16, 30, "Clip OFF." );

   getch();
   closegraph();
}
