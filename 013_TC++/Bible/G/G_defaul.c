/*                                */
/*    Program Name: g_defaul.c    */
/*                                */
#include <conio.h>
#include <graphics.h>

void OutputFun( int );

void main( void )
{
   int GraphDriver = DETECT, GraphMode, MaxY;
   unsigned LinePattern;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   MaxY = getmaxy();
   /*  Setting text, fill and line style.  */
   settextstyle( TRIPLEX_FONT, HORIZ_DIR, 3 );
   setfillstyle( LTBKSLASH_FILL, 3 );
   setlinestyle( DOTTED_LINE, LinePattern, THICK_WIDTH );

   OutputFun( 0 );
   outtextxy( 10, MaxY/2-30, "After call graphdefaults.." );
   graphdefaults();
   OutputFun( MaxY/2 );

   getch();
   closegraph();
}

void OutputFun( int StartY )
{
   outtextxy( 10, StartY+10, "TEXT: C Bible" );
   outtextxy( 10, StartY+30, "LINE:" );
   line( 70, StartY+40, 200, StartY+40 );
   outtextxy( 10, StartY+50, "FILL STYLE:" );
   bar( 150, StartY+50, 200, StartY+80 );
}
