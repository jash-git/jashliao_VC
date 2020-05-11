/*                                */
/*    Program Name: G_M_MODE.C    */
/*                                */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   char OutText[50];

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   sprintf( OutText, "The maximum graphics mode no. is %d",
	    getmaxmode() );
   outtextxy( getmaxx()/2-70, getmaxy()/2, OutText );

   getch();
   closegraph();
}
