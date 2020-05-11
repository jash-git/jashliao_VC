/*                                */
/*    Program Name: movedata.c    */
/*                                */
#include <dos.h>
#include <mem.h>
#include <stdio.h>

void main( void )
{
   char CopyRight[81];
   unsigned BuffSeg, BuffOff;

   /*  Get the buffer CopyRight segment & offset
       address.  */
   BuffSeg = FP_SEG( ( char far * )CopyRight );
   BuffOff = FP_OFF( ( char far * )CopyRight );

   /*  Get the copyright notice.  */
   movedata( 0xf000, 0xe000, BuffSeg, BuffOff, 47 );
   CopyRight[47] = '\0';
   printf( "%s\n", CopyRight );
}
