/*                                */
/*    Program Name: g_d_name.c    */
/*                                */
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   char *DriverName;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );
   DriverName = getdrivername();
   closegraph();

   printf( "Your graphics driver name is %s.BGI.\n",
           DriverName );
}
