/*                               */
/*    Program Name: realloc.c    */
/*                               */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   char *MemBlk;

   MemBlk = ( char * )malloc( 81 );
   if( MemBlk == NULL ) {
      printf( "Allocated memory failed!\a\n" );
      abort();
   }

   printf( "Memory allocated.\n" );
   printf( "Please input a string: " );
   gets( MemBlk );
   printf( "This string is \"%s\".\n", MemBlk );

   /*  Enlarge the memory.  */
   MemBlk = realloc( MemBlk, 256 );
   if( MemBlk == NULL ) {
      printf( "Memory adjusted failed!\a\n" );
      abort();
   }
   printf( "Memory adjusted succeed.\n" );
   printf( "The memory adjusted also contain \"%s\".\n",
           MemBlk );

   free( MemBlk );
}
