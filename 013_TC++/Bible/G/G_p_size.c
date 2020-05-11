/*                                */
/*    Program Name: g_p_size.c    */
/*                                */
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int PaleSize;
   char *DriverName;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );
   DriverName = getdrivername();
   PaleSize = getpalettesize();
   closegraph();

   printf( "Your graphics driver name is %s.BGI\n",
           DriverName );
   printf( "The current palette has %d colors.\n",
           PaleSize );
}
