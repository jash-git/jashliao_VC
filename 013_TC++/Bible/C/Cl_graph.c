/*                                */
/*    Program Name: cl_graph.c    */
/*                                */
#include <graphics.h>

void main( void )
{
   int ErrorCode, GraphDriver = DETECT, GraphMode;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   ErrorCode = graphresult();
   if( graphresult() != grOk ) {
      printf( "Graphics error: %s\n",
              grapherrormsg( ErrorCode ) );
      abort();
    }

    settextjustify( CENTER_TEXT, CENTER_TEXT );
    settextstyle( TRIPLEX_FONT, HORIZ_DIR, 3 );
    outtextxy( getmaxx()/2, getmaxy()/2, "C Bible" );
    outtextxy( getmaxx()/2, getmaxy()/2+50,
               "Press any key to return text mode.." );
    getch();
    closegraph();
}
