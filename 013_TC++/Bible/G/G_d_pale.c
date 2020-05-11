/*                                */
/*    Program Name: g_d_pale.c    */
/*                                */
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   char *DriverName;
   struct palettetype far *Palette;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );
   DriverName = getdrivername();
   Palette = getdefaultpalette();
   closegraph();

   printf( "Your graphics driver name is %s.BGI.\n",
           DriverName );
   printf( "There are %d color in the palette.\n",
           Palette->size );
}
