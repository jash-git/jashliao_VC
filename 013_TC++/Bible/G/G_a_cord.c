/*                                */
/*    Program Name: g_a_cord.c    */
/*                                */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   struct arccoordstype ArcInfo;

   initgraph(&GraphDriver, &GraphMode, "..\\BGI" );

   /*  Top-Right corner.  */
   arc( 400, 120, 0, 89, 50 );
   getarccoords( ( struct arccoordstype far * ) &ArcInfo );
   line( ArcInfo.xstart, ArcInfo.ystart,
	 ArcInfo.xstart, ArcInfo.ystart+50 );
   line( ArcInfo.xend,     ArcInfo.yend,
	 ArcInfo.xend-100, ArcInfo.yend );

   /*  Bottom-Left corner.  */
   arc( ArcInfo.x-100, ArcInfo.y+50, 180, 269, 50 );
   getarccoords( ( struct arccoordstype far * ) &ArcInfo );
   line( ArcInfo.xstart, ArcInfo.ystart,
	 ArcInfo.xstart, ArcInfo.ystart-50 );
   line( ArcInfo.xend,     ArcInfo.yend,
	 ArcInfo.xend+100, ArcInfo.yend );

   /*  Bottom-Right concern.  */
   arc( ArcInfo.x+100, ArcInfo.y, 270, 359, 50 );

   /*  Top-Left concern.  */
   arc( ArcInfo.x, ArcInfo.y-50, 90, 179, 50 );

   getch();
   closegraph();
}
