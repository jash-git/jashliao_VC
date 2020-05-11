/*                               */
/*    Program Name: _c_exit.c    */
/*                               */
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <dos.h>

/*                             */
/*    Function Prototyping.    */
/*                             */
void fun( void );

void main( void )
{
   FILE *fp;
   char FileName[81], Content[256];

   atexit( fun );

   printf( "Please input a existing file name: " );
   gets( FileName );

   /*  Open file.  */
   if( ( fp = fopen( FileName, "r" ) ) == NULL ) {
      printf( "File not found!\a\n" );
      abort();
   }

   printf( "TNT 0h at %Fp before call \"_c_exit\".\n", _dos_getvect(0) );

   _c_exit();

   printf( "TNT 0h at %Fp after call \"_c_exit\".\n", _dos_getvect(0) );
   if( fscanf( fp, "%s", Content ) == EOF )
      printf( "Reading failed after call \"_c_exit\".\n" );
   else
      printf( "Reading OK after call \"_c_exit\".\n" );

   fclose( fp );
}

/*  Function will be called when main() is stop.  */
void fun( void )
{
   printf( "The function \"fun\" is called!\n" );
}
