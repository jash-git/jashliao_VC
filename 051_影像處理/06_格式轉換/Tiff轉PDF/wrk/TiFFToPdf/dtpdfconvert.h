//************************
//*      Chris Rubio     *
//*                      *
//*  Copyright (C) 2000  *
//*                      *
//*  dtpdfconvert.h      *
//************************
/*
    You are free to use,modify,make,sell,share or do whatever you want with this code.
    thanks to tifflib, and CxImage class, ImageMagick for inspiration. Please send any modifications to 
    +s i r r u b e 2 @ y a h o o . c o m+ so I can implement them as well if I choose. 

    Thanks to all the coders on code project in the past who have shared thier source as well.

    To build you need CXImage and libtiff.  /cvsroot/osrs/libtiff/libtiff.

*   THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND
*   EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY 
*   WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.


*/
//****************************************************************************
//*                              REVISION HISTORY                            *
//****************************************************************************
//*   Date   *                                                     *   Who   *
//****************************************************************************
//* 11/8/2002* Created header file.                                *   CLR   *
//****************************************************************************
#ifndef DTPDFCONVERT_H
#define DTPDFCONVERT_H

#include "dtimageinfo.h"

class CDTPDFConvert
{
public:

  CDTPDFConvert() { memset(m_szErrorCode, 0, sizeof(char) * 255 );};
  ~CDTPDFConvert() {};

  int TiffToPdf( char* a_tiff, char* a_pdf, char* a_szCreator = NULL,  char* a_szCreationDate = NULL,
                        char * a_szAuthor = NULL, char * a_szProducer = NULL, char * a_szTitle = NULL, char * a_szSubject = NULL, 
                        char * a_szKeywords = NULL );

  char m_szErrorCode[ 255 ];

private:
  int tiff_writePDFColorSpace( FILE * pf, long nObj, QTiff & qt, fpos_t & start, fpos_t & end );
  int tiff_writePDFXObjectLength( FILE * pf, long nObj, QTiff & qt, fpos_t & start, fpos_t & end );
  int tiff_writePDFXObject( FILE * pf, long nObj, QTiff & qt, fpos_t & start, fpos_t & end );
  int tiff_writePDFProcsetObject( FILE * pf, long nObj, QTiff & qt, fpos_t & start, fpos_t & end );
  int tiff_writePDFContentsObject( FILE * pf, long nObj, QTiff & qt, fpos_t & start, fpos_t & end );
  int tiff_writePDFPageObject( FILE * pf, long nObj, long pages_id , QTiff & qt );
  int tiff_writePDFPagesObject( FILE * pf, long nObj, QTiff & qt );
  int tiff_writePDFCatalogObject( FILE * pf, long nObj );
  int tiff_writePDFInfoObject( FILE * pf, char* a_szCreator, char* a_szCreationDate, char * a_szAuthor, char * a_szProducer, char * a_szTitle, char * a_szSubject,  char * a_szKeywords  );

  int tiff_dumpTiffCCITTRLE( FILE * pf, QTiff & qt );
  int tiff_dumpTiffFAX( FILE * pf, QTiff & qt );
  int tiff_dumpTiffRLE( FILE * pf, QTiff & qt );

};




#endif
