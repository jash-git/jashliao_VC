/*                              */
/*    Program Name: memchr.c    */
/*                              */
#include <dos.h>
#include <mem.h>
#include <stdio.h>

void main( void )
{
   char far *Addr, Buff[81], ch, *FirstAddr, *EndAddr;
   int i = 0;

   /*  Get the copyright notice at F000:E000, and put
       it into Buff.  */
   Addr = MK_FP( 0xf000, 0xe000 );
   for( ch = *Addr; ch; Addr++, ch = *Addr )
      Buff[i++] = ch;
   Buff[i] = '\0';

   /*  Search for 'I'BM in the Buff.  */
   if( ( FirstAddr = memchr( Buff, 'I', 24 ) ) == NULL )
      printf( "Search failed!\n" );
   else
   {
      EndAddr = memchr( Buff, '.', 80 );
      *( EndAddr + 1 ) = '\0';
      printf( "%s\n", FirstAddr );
   }
}
