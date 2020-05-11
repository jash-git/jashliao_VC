/*                                */
/*    Program Name: f_reallo.c    */
/*                                */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   char far *MemBlk1, far *MemBlk2;

   /*  Allocated memory block.  */
   if( ( MemBlk1 = farmalloc( 1000l ) ) == NULL ) {
      printf( "Allocated memory block1 failed!\a\n" );
      abort();
   }

   /*  Allocated memory block.  */
   if( ( MemBlk2 = farmalloc( 1000l ) ) == NULL ) {
      printf( "Allocated memory block2 failed!\a\n" );
      abort();
   }

   printf( "Memory block1 of 1000 bytes allocated " );
   printf( "at %Fp.\n", MemBlk1 );
   printf( "Memory block2 of 1000 bytes allocated " );
   printf( "at %Fp.\n", MemBlk2 );

   if( ( MemBlk1 = farrealloc( MemBlk1, 2000l ) ) == NULL
     ) {
      printf( "Memory block1 adjusted failed!\a\n" );
      abort();
   }

   printf( "Now, we adjusted memory block1 to 2000 " );
   printf( "bytes at %Fp.\n", MemBlk1 );
}
