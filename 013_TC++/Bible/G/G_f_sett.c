/*                                */
/*    Program Name: g_f_sett.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void main( void )
{
   struct fillsettingstype PattInfo;
   int GraphDriver = DETECT, GraphMode;
   int MaxColor;
   char PattName[][16] = { "EMPTY_FILL", "SOLID_FILL",
        "LINE_FILL", "LTSLASH_FILL", "SLASH_FILL",
        "BKSLASH_FILL", "LTBKSLASH_FILL", "HATCH_FILL",
        "XHATCH_FILL", "INTERLEAVE_FILL", "WIDE_DOT_FILL",
        "CLOSE_DOT_FILL" }, OutPatt[16];

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   randomize();

   MaxColor = getmaxcolor();
   do {
      setfillstyle( random( 12 ), random( MaxColor+1 ) );
      getfillsettings( &PattInfo );
      bar( 50, 50, 100, 100 );
      sprintf( OutPatt, "This Pattern is %s",
               PattName[PattInfo.pattern] );
      outtextxy( 50, 110, OutPatt );
      delay( 500 );

      /*  Clear text.  */
      setfillstyle( EMPTY_FILL, 0 );
      bar( 50, 110, 300, 120 );
   } while( !kbhit() );

   closegraph();
}
