/*                              */
/*    Program Name: _cexit.c    */
/*                              */
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
   char FileName[81];

   atexit( fun );

   printf( "Please input a existing file name: " );
   gets( FileName );

   /*  Open file.  */
   if( ( fp = fopen( FileName, "w+" ) ) == NULL ) {
      printf( "File not found!\a\n" );
      abort();
   }

   printf( "TNT 0h at %Fp before call \"_cexit\".\n", _dos_getvect(0) );

   _cexit();

   printf( "TNT 0h at %Fp after call \"_cexit\".\n", _dos_getvect(0) );
   printf( "The \"_cexit\" function can't close all " );
   printf( "files, \nso you can see \"Hello!\" message " );
   printf( "in the file.\n" );
   fprintf( fp, "Hello!" );
   fclose( fp );
}

/*  Function will be called when main() is stop.  */
void fun( void )
{
   printf( "The function \"fun\" is called when the " );
   printf( "\"_cexit\" is called!\n" );
}
