/*                                */
/*    Program Name: g_b_colo.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int OldBkColor, MaxColor, Color;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   MaxColor = getmaxcolor();
   /*  Save old background color.  */
   OldBkColor = getbkcolor();
   outtextxy( getmaxx()/2-160, getmaxy()/2, "Press <Enter> to\
 EXIT, another key to switch color.." );

   randomize();

   do {
      Color = random( MaxColor+1 );
      setbkcolor( Color );
   } while( getch() != 13 );

   setbkcolor( OldBkColor );
   closegraph();
}
