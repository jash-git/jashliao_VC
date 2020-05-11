/*                                */
/*    Program Name: g_f_patt.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main( void )
{
   unsigned char Pattern[8] = { 0x81, 0x42, 0x24, 0x18,
                                0x18, 0x24, 0x42, 0x81 },
                 CurrPatt[8];

   char OutPatt[81];
   int  GraphDriver = DETECT, GraphMode, i;

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );

   setfillpattern( Pattern, LIGHTRED );
   getfillpattern( CurrPatt );
   sprintf( OutPatt, "%x %x %x %x %x %x %x %x",
            CurrPatt[0], CurrPatt[1], CurrPatt[2],
            CurrPatt[3], CurrPatt[4], CurrPatt[5],
            CurrPatt[6], CurrPatt[7] );

   bar( 100, 100, 300, 300 );
   outtextxy( 100, 310, "The Pattern is " );
   outtextxy( 220, 310, OutPatt );

   getch();
   closegraph();
}
