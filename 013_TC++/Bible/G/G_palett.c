/*                                */
/*    Program Name: g_palett.c    */
/*                                */
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   char *DriverName, i;
   struct palettetype Palette;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );
   DriverName = getdrivername();
   getpalette( &Palette );
   closegraph();

   printf( "Your graphics driver name is %s.BGI.\n",
           DriverName );
   printf( "There are %d color in the current palette.\n",
           Palette.size );

   printf( "The color values are " );
   for( i = 0; i < Palette.size; i++ )
      printf( "%d\n                     ",
              Palette.colors[i] );
}
