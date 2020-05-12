// TiFFToPdf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dtpdfconvert.h"
//#include "lisa2tiff.h"



int main(int argc, char* argv[])
{

  CDTPDFConvert convert;


/*  if(argc >= 2) {
    convert.TiffToPdf( argv[ 1 ], NULL );
  } 
  */

  convert.TiffToPdf( "C:\\03.tif", NULL );

  printf("Finished!\n");
  return 0;
}

