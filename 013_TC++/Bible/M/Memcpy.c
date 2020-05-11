/*                              */
/*    Program Name: memcpy.c    */
/*                              */
#include <mem.h>
#include <stdio.h>

void main( void )
{
   char Source[81] = "C Bible";
   char Dest[81] = "dummy";

   printf( "Before copy:\n" );
   printf( "  Source = \"%s\".\n", Source );
   printf( "  Dest   = \"%s\".\n", Dest );

   memcpy( Dest, Source, 81 );
   printf( "After copy:\n" );
   printf( "  Source = \"%s\".\n", Source );
   printf( "  Dest   = \"%s\".\n", Dest );

}
