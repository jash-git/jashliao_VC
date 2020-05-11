/*                                */
/*    Program Name: g_g_mode.c    */
/*                                */
#include <conio.h>
#include <graphics.h>

void main( void )
{
   int GraphDriver = DETECT, GraphMode, CurrMode;
   char OutText[80];
   struct G_Drv {
      int No;
      char Name[10];
   } GraphDrv[10] =
     { { CGA, "CGA" },          { MCGA, "MCGA" },
       { EGA, "EGA" },          { EGA64, "EGA64" },
       { EGAMONO, "EGAMONO" },  { IBM8514, "IBM8514" },
       { HERCMONO, "HERCMONO" },{ ATT400, "ATT400" },
       { VGA, "VGA" },          { PC3270, "PC3270" } },
     *CurrDrv;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   CurrMode = getgraphmode();
   CurrDrv = ( struct G_Drv * )memchr( GraphDrv,
             GraphDriver, sizeof( GraphDrv ) );
   sprintf( OutText, "You are in %s mode %d", CurrDrv->Name,
            CurrMode );
   outtextxy( getmaxx()/2-40, getmaxy()/2, OutText );

   getch();
   closegraph();
}
