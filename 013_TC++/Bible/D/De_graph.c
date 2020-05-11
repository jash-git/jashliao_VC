/*                                */
/*    Program Name: de_graph.c    */
/*                                */
#include <graphics.h>

void main( void )
{
   int ErrorCode, GraphDriver, GraphMode;
   struct GraDrv{
      int  DriverConst;
      char DriverMsg[81];
   } DriverArray[9] =
     { { CGA,      "Color Graphics Adapter" },
       { MCGA,     "Multicolor Graphics Array" },
       { EGA,      "Enhanced Graphics Adapter" },
       { EGA64,    "Enhanced Graphics Adapter" },
       { EGAMONO,  "Enhanced Graphics Adapter" },
       { HERCMONO, "Hercules Color Card" },
       { ATT400,   "AT&T 640x400 Card" },
       { VGA,      "Video Graphics Array or IBM 8514" },
       { PC3270,   "IBM PC 3270" } }, *DrvPtr;

   /*  Determine hardware.  */
   detectgraph( &GraphDriver, &GraphMode );
   if( GraphDriver < 0 ) {
      printf( "Can't find suitable graphic driver!\a\n" );
      abort();
   }

   /*  Search the Graphics Driver message in
       DriverArray.  */
   DrvPtr = ( struct GraDrv * )memchr( DriverArray,
            GraphDriver, sizeof( DriverArray ) );

   printf( "Your graphics adapter is %s\n",
           DrvPtr->DriverMsg );
}
