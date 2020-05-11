/*                                */
/*    Program Name: g_m_rang.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   struct G_Drv {
      int No;
      char Name[15];
   } GraphDrv[] =
     { { CGA, "CGA" },           { MCGA, "MCGA" },
       { EGA, "EGA" },           { EGA64, "EGA64" },
       { EGAMONO, "EGAMONO" },   { IBM8514, "IBM8514" },
       { HERCMONO, "HERCMONO" }, { ATT400, "ATT400" },
       { VGA, "VGA" },           { PC3270, "PC3270" } },
     *SelDrv;
   int i, LoMode, HiMode;

   printf( "Search the graphics driver's mode range:\n" );
   printf( "---------------------------------------\n" );
   for( i = 0; i < 10; i++ )
      printf( "%d.%s\n", i, GraphDrv[i].Name );
   printf( "---------------------------------------\n" );
   printf( "  Select:  " );
   do {
      printf( "\b" );
      i = getche() - 48;
   } while( i < 0 && i > 9 );
   printf( "\n---------------------------------------\n" );

   SelDrv = ( struct G_Drv * )memchr( GraphDrv, i+1,
              sizeof( GraphDrv ) );
   getmoderange( i+1, &LoMode, &HiMode );
   printf( "\nThe %s mode range is %d to %d.\n",
           SelDrv->Name, LoMode, HiMode );
}
