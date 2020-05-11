/*                                */
/*    Program Name: s_b_colo.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int OldBkColor, MaxColor, Color;
   char OutText[30];
   struct ColorTable {
      int No;
      char Name[15];
   } ColorList[16] =
     { { BLACK, "BLACK" }, { BLUE,      "BLUE" },
       { GREEN, "GREEN" }, { CYAN,      "CYAN" },
       { RED,   "RED"   }, { MAGENTA,   "MAGENTA" },
       { BROWN, "BROWN" }, { LIGHTGRAY, "LIGHTGRAY" },
       { DARKGRAY,     "DARKGRAY"     },
       { LIGHTBLUE,    "LIGHTBLUE"    },
       { LIGHTGREEN,   "LIGHTGREEN"   },
       { LIGHTCYAN,    "LIGHTCYAN"    },
       { LIGHTRED,     "LIGHTRED"     },
       { LIGHTMAGENTA, "LIGHTMAGENTA" },
       { YELLOW, "YELLOW" }, { WHITE, "WHITE" } }, *ColPtr;

   /*  Register graphics drivers.  */
   if( registerbgidriver( Herc_driver ) < 0 ) {
      printf( "HERC driver registered failed!\a\n" );
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

   MaxColor = getmaxcolor();
   /*  Save old background color.  */
   OldBkColor = getbkcolor();

   randomize();

   do {
      clearviewport();
      Color = random( MaxColor+1 );
      /*  Search the color name.  */
      ColPtr = ( struct ColorTable * )memchr( ColorList,
               Color, sizeof( ColorList ) );
      sprintf( OutText, "The color is %s.", ColPtr->Name );
      outtextxy( 0, 0, OutText );
      outtextxy( getmaxx()/2-160, getmaxy()/2, "Press <Ente\
r> to EXIT, another key to switch color.." );
      setbkcolor( Color );
   } while( getch() != 13 );

   setbkcolor( OldBkColor );
   closegraph();
}
