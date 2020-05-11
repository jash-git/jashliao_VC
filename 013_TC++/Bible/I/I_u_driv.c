/*                                */
/*    Program Name: i_u_driv.c    */
/*                                */
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

/*    Function Prototyping.    */
int huge Check_VGA( void );
void DetectError( void );

void main( void )

{
   int GraphDriver, GraphMode;

   /*  Install a new BGI driver.  */
   GraphDriver = installuserdriver( "VGA", Check_VGA );
   DetectError();

   initgraph( &GraphDriver, &GraphMode, "..\\BGI" );
   DetectError();

   circle( getmaxx()/2, getmaxy()/2, 100 );

   outtextxy( getmaxx(), getmaxy(), "Press any key.." );
   getch();
   closegraph();
}

void DetectError( void )
{
   int ErrNo;

   /*  Detect Errors.  */
   ErrNo = graphresult();
   if( ErrNo != grOk )
   {
      printf( "Graphics error(%d): %s\n", ErrNo,
              grapherrormsg( ErrNo ) );
      exit( 1 );
   }
}

int huge Check_VGA( void )
{
   int GraphDriver, GraphMode;

   detectgraph(&GraphDriver, &GraphMode);

   if( GraphDriver == VGA )
      return 2;
   else
      return grError;
}
