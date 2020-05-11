/*                            */
/*    Program Name: exit.c    */
/*                            */
#include <stdio.h>
#include <stdlib.h>

/*                             */
/*    Function Prototyping.    */
/*                             */
void fun( void );

void main( void )
{
   FILE *fp;
   char FileName[81];

   atexit( fun );

   printf( "Please input a existing file name: " );
   gets( FileName );

   /*  Open file.  */
   if( ( fp = fopen( FileName, "w+" ) ) == NULL ) {
      printf( "File not found!\a\n" );
      abort();
   }

   /*  Output data to buffer.  */
   fprintf( fp, "The function \"exit\" will flush " );
   fprintf( fp, "the buffers!\n" );
   fprintf( fp, "So, you can see this message in " );
   fprintf( fp, "this file!\n" );
   printf( "The function \"exit\" flushed the buffers!\n" );

   exit( 0 );
}

/*  Function will be called when main() is stop.  */
void fun( void )
{
   printf( "The function \"fun\" is called when the " );
   printf( "main program is stop!\n" );
}
