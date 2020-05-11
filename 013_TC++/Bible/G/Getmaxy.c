/*                               */
/*    Program Name: getmaxy.c    */
/*                               */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int MaxX, MaxY;
   char OutText[80];

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   MaxX = getmaxx();
   MaxY = getmaxy();

   /*  Display maximum x coordinate.  */
   sprintf( OutText, "The maximum x coordinate is %d.",
            MaxX );
   outtextxy( 10, 10, OutText );

   /*  Display maximum y coordinate.  */
   sprintf( OutText, "The maximum y coordinate is %d.",
            MaxY );
   outtextxy( 10, 20, OutText );

   /*  Display center pointer coordinate.  */
   sprintf( OutText, "The center pointer coordinate is (%d,\
%d).", MaxX/2, MaxY/2 );
   outtextxy( 10, 30, OutText );

   getch();
   closegraph();
}
