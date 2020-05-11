/*                                */
/*    Program Name: g_result.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode;
   int ErrorCode;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   ErrorCode = graphresult();
   if( ErrorCode != grOk ) {
      printf( "Error(%d): %s\a\n", ErrorCode,
              grapherrormsg( ErrorCode ) );
      exit( 1 );
   }

   outtextxy( 0, 0, "No error occur! Press any key to retur\
n TEXT mode.." );
   getch();
   closegraph();
}
