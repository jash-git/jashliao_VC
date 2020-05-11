/*                                */
/*    Program Name: g_l_sett.c    */
/*                                */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   struct linesettingstype LineInfo;
   int GraphDriver = DETECT, GraphMode;
   char OutText[80];
   struct L_Style{
      int No;
      char Name[15];
   } LineStyle[5] = { { SOLID_LINE,   "SOLID_LINE" },
                      { DOTTED_LINE,  "DOTTED_LINE" },
                      { CENTER_LINE,  "CENTER_LINE" },
                      { DASHED_LINE,  "DASHED_LINE" },
                      { USERBIT_LINE, "USERBIT_LINE" } },
     *DefaLine;
   struct L_Thick {
      int No;
      char Name[15];
   } LineThick[2] = { { NORM_WIDTH,  "NORM_WIDTH" },
                      { THICK_WIDTH, "THICK_WIDTH" } },
     *DefaThick;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   getlinesettings( &LineInfo );
   DefaLine = ( struct L_Style * )memchr( LineStyle,
              LineInfo.linestyle, sizeof( LineStyle ) );
   DefaThick = ( struct L_Thick * )memchr( LineThick,
               LineInfo.thickness, sizeof( LineThick ) );
   sprintf( OutText, "The default line style is %s, \
thickness is %s.", DefaLine->Name, DefaThick->Name );

   outtextxy( 10, 10, OutText );
   outtextxy( 10, 20, "Example: " );
   line( 75, 23, 330, 23 );

   getch();
   closegraph();
}
