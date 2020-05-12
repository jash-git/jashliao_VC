//************************
//*      Chris Rubio     *
//*                      *
//*  Copyright (C) 2002  *
//*                      *
//*  dtpdfconvert.cpp    *
//************************
/*
  "I swear by my life and my love of it that I will never live for the
   sake of another man, nor ask another man to live for mine"

                    John Galt in "Atlas Shrugged", by Ayn Rand

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
//* 11/8/2002* Created source file.                                *   CLR   *
//****************************************************************************
#include "stdafx.h"
#include "dtimageinfo.h"
#include "dtpdfconvert.h"
#include "rlecodec.h"
#include "math.h"

#define ScaleCharToQuantum(value)    ((257UL*(value)))
#define ScaleQuantumToChar(quantum)  (((quantum)/257UL))


/****************************************************************************/
/*                                                                          */
/*  CDTPDFConvert::tiff_writePDFXObjectLength                               */
/*                                                                          */
/****************************************************************************/
int CDTPDFConvert::tiff_writePDFXObjectLength( FILE * pf, long nObj, QTiff & qt, fpos_t & start, fpos_t & end )
{

  try {
    CString czbuf;
    fpos_t offset = end - start;

    czbuf.Format( "%lu\r",(unsigned long) offset);
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "endobj\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
  } catch(...)
  {
    throw -10;
  }

  return 1;
}

int CDTPDFConvert::tiff_dumpTiffRLE( FILE * pf, QTiff & qt )
{

  unsigned char * scanline = NULL;
  BYTE * pImage = NULL;
  BYTE * pRLED = NULL;

  try {

    uint16 fillorder;
    TIFFGetFieldDefaulted( qt.m_tif,TIFFTAG_FILLORDER,&fillorder );
    
    long lScanLineSize = ( 8 * TIFFScanlineSize( qt.m_tif ));
    long uncompressed_len = (1 + (qt.height * qt.width * (qt.bitspersample > 8 ? 2 : 1)));

    if (qt.photometric == PHOTOMETRIC_RGB || qt.m_bIsRGB) 
      uncompressed_len *= 3;


    scanline = (unsigned char *) malloc( lScanLineSize );

    pImage = (BYTE *) malloc( uncompressed_len );

    pRLED = (BYTE *) malloc( uncompressed_len );

    memset( pImage, 0xB, uncompressed_len );

    BYTE * p, *r;

    r = pImage;


    int i, x = 0;
    for ( int y = 0; y < (long)qt.height; y++) {
      TIFFReadScanline(qt.m_tif,(char *) scanline,(uint32) y,0);

      p = scanline;

      if (fillorder == FILLORDER_LSB2MSB)
        TIFFReverseBits( scanline,lScanLineSize );

      if (qt.photometric == PHOTOMETRIC_RGB || qt.m_bIsRGB) {
        for (x=0; x < (long) qt.width; x++) {
          BYTE pixel = *p++;
          *r++       =  pixel ;
          pixel      = *p++;
          *r++       =  pixel ;
          pixel      = *p++;
          *r++       =  pixel ;
        }
        continue;
      }

      switch (qt.bitspersample)
      {
        case 1:
        {
          register long
            bit;

          for (x=0; x < ((long) qt.width-7); x+=8)
          {
            for (bit=7; bit >= 0; bit--)
              *r++=((*p) & (0x01 << bit) ? 0x01 : 0x00);
            p++;
          }
          if ((qt.width % 8) != 0)
            {
              for (bit=7; bit >= (long) (8-(qt.width % 8)); bit--)
                *r++=((*p) & (0x01 << bit) ? 0x01 : 0x00);
              p++;
            }
          break;
        }
        case 2:
        {
          for (x=0; x < ((long) qt.width-3); x+=4)
          {
            *r++=(*p >> 6) & 0x3;
            *r++=(*p >> 4) & 0x3;
            *r++=(*p >> 2) & 0x3;
            *r++=(*p) & 0x3;
            p++;
          }
          if ((qt.width % 4) != 0)
            {
              for (i=3; i >= (long) (4-(qt.width % 4)); i--)
                *r++=(*p >> (i*2)) & 0x03;
              p++;
            }
          break;
        }
        case 4:
        {
          for (x=0; x < ((long) qt.width-1); x+=2)
          {
            *r++=(*p >> 4) & 0xf;
            *r++=(*p) & 0xf;
            p++;
          }
          if ((qt.width % 2) != 0)
            *r++=(*p++ >> 4) & 0xf;
          break;
        }
        case 8:
        {
          for (x=0; x < (long) qt.width; x++)
            *r++=(*p++);
          break;
        }
        case 16:
        {
          if (qt.bitspersample <= 8)
            {
              for (x=0; x < (long) qt.width; x++)
              {
                *r=(*p++) << 8;
                *r|=(*p++);
                r++;
              }
              break;
            }
          for (x=0; x < (long) qt.width; x++)
          {
            *r++=(*p++);
            *r++=(*p++);
          }
          break;
        }
        default:
          break;
      }
    }

    long count = DTTPackbitsEncodeImage( pRLED, pImage, uncompressed_len  );
    fwrite( pRLED, count, 1, pf );


  } catch(...) {
    free( scanline );
    free( pImage );
    free( pRLED );

    return 0;
  }

  free( scanline );
  free( pImage );
  free( pRLED );

  return 1;
}

int CDTPDFConvert::tiff_dumpTiffCCITTRLE( FILE * pf, QTiff & qt )
{

  unsigned char * scanline = NULL;
  unsigned char * pImage = NULL;
  unsigned char * pRLED = NULL;

  try {

    uint16 fillorder;
    TIFFGetFieldDefaulted( qt.m_tif,TIFFTAG_FILLORDER,&fillorder );
    
    long lScanLineSize = ( 8 * TIFFScanlineSize( qt.m_tif ));
    long uncompressed_len = ((lScanLineSize * 8) * qt.height * (qt.bitspersample > 8 ? 2 : 1));
    scanline = (unsigned char *) malloc( lScanLineSize );
    pImage = (unsigned char *) malloc( uncompressed_len );
    pRLED = (unsigned char *) malloc( uncompressed_len );

    unsigned char * p, *r;

    r = pImage;

    for ( int y = 0; y < (long)qt.height; y++) {
      TIFFReadScanline(qt.m_tif,(char *) scanline,(uint32) y,0);

      p = scanline;

      if (fillorder == FILLORDER_LSB2MSB)
        TIFFReverseBits( scanline,lScanLineSize );

      register long bit;

      for ( int x = 0; x < ((long)qt.width - 7 ); x += 8) {
        for ( bit=7; bit >= 0; bit-- )
          *r++=((*p) & (0x01 << bit) ? 0x01 : 0x00);
        p++;
      }

      if ((qt.width % 8) != 0) {
        for (bit=7; bit >= (long) (8-(qt.width % 8)); bit--)
          *r++=((*p) & (0x01 << bit) ? 0x01 : 0x00);

        p++;
      }

    }

    //
    //  set the correct color coding.
    //
    BYTE black, white;

    switch (qt.photometric)
    {
      case PHOTOMETRIC_MINISBLACK:
        black = 0xFF;
        white = 0x00;
        break;

      case PHOTOMETRIC_MINISWHITE:
        black = 0x00;
        white = 0xFF;
      default:
        break;
    }

    for ( y = 0 ; y < uncompressed_len; y++ ) {
      if (pImage[ y ] == 0)
        pImage[ y ] = white;
      else
        pImage[ y ] = black;
    }

    long count = DTTPackbitsEncodeImage( pRLED, pImage, uncompressed_len );
    fwrite( pRLED, count, 1, pf );


  } catch(...) {
    free( scanline );
    free( pImage );
    free( pRLED );
    return 0;
  }

  free( scanline );
  free( pImage );
  free( pRLED );

  return 1;
}


int CDTPDFConvert::tiff_dumpTiffFAX( FILE * pf, QTiff & qt )
{

  //
  //  write out buffer.
  //
  unsigned long * byte_count, strip_size;
  unsigned char * buffer = NULL;
  uint16 fillorder;
  long count = 0;

  try {
    //
    // Allocate raw strip buffer.
    //
    (void) TIFFGetField( qt.m_tif ,TIFFTAG_STRIPBYTECOUNTS,&byte_count );
    strip_size = byte_count[ 0 ];
    for (int i = 1; i < (long) TIFFNumberOfStrips( qt.m_tif ); i++)
      if (byte_count[ i ] > strip_size )
        strip_size = byte_count[ i ];

    buffer = (unsigned char *) new unsigned char[ strip_size ];
    if (buffer == (unsigned char *) NULL) {
      throw -11;
    }

    //
    // Get the bits.
    //
    (void)TIFFGetFieldDefaulted( qt.m_tif,TIFFTAG_FILLORDER,&fillorder );
    for (i=0; i < (long) TIFFNumberOfStrips( qt.m_tif ); i++) {
      count = TIFFReadRawStrip( qt.m_tif,(uint32) i,buffer,(long) byte_count[ i ] );
      if (fillorder == FILLORDER_LSB2MSB)
        TIFFReverseBits( buffer,count );

      //
      //  write out the image
      //
      fwrite( buffer, count, 1 , pf );
    }
  } catch(...) {
    delete[] buffer;
    return 0;
  }

  delete[] buffer;
  return 1;
}

int CDTPDFConvert::tiff_writePDFColorSpace( FILE * pf, long nObj, QTiff & qt, fpos_t & start, fpos_t & end )
{

  try {

    CString czbuf;

    //
    //  If it is a color image and is
    //
    long count_colors = 1 << qt.bitspersample;

    if (qt.photometric == PHOTOMETRIC_SEPARATED) {
      czbuf = "/DeviceCMYK\rendobj\r";
      fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
    } else if (count_colors > 2) {

      if (qt.photometric == PHOTOMETRIC_RGB && qt.m_bIsRGB) {
        czbuf = "/DeviceRGB\r";
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
      } else {
        czbuf.Format("[ /Indexed /DeviceRGB %lu %lu 0 R ]\r", count_colors - 1, nObj + 1) ;
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
        return 2;
      }

    } else {
      czbuf = "/DeviceGray\rendobj\r";
      fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
    }

  } catch(...)
  {
    throw -15;
  }

  return 1;
}


/****************************************************************************/
/*                                                                          */
/*  CDTPDFConvert::tiff_writePDFXObject                                     */
/*                                                                          */
/****************************************************************************/
int CDTPDFConvert::tiff_writePDFXObject( FILE * pf, long nObj, QTiff & qt, fpos_t & start, fpos_t & end )
{

  try {

    CString czbuf;
    CString czColorSpace;
    long bitspercomponet = 1;

    czbuf = "<<\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "/Type /XObject\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "/Subtype /Image\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Name /Im%lu\r",qt.page() );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    //
    //  Determine what typeof image it is.
    //
    long lEncodingscheme = -1;

    switch(qt.compression) {
      case COMPRESSION_CCITTFAX3:
        lEncodingscheme = 0;
      case COMPRESSION_CCITTFAX4:
        {
          czbuf = "/Filter /CCITTFaxDecode\r";
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

          czbuf.Format( "/DecodeParms << /K %i /Columns %ld /Rows %ld >>\r",lEncodingscheme, qt.width,qt.height);
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
          break;
        }
      case COMPRESSION_LZW:
        {
          czbuf = "/Filter /LZWDecode\r";
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
          break;
        }
      case COMPRESSION_CCITTRLE:
      default:
        {
          bitspercomponet = 8;   // Need to uncompress the image here.
          czbuf = "/Filter /RunLengthDecode\r";
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
          break;
        }
    }

    //
    //  write out colorspace always 2 in front.
    //
    czColorSpace.Format( "/ColorSpace %lu 0 R\r",nObj + 2);
    fwrite( (LPCSTR)czColorSpace, czColorSpace.GetLength(), 1, pf );

    czbuf.Format( "/Width %lu\r",qt.width );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Height %lu\r",qt.height );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );


    czbuf.Format( "/BitsPerComponent %d\r", bitspercomponet );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Length %lu 0 R\r",nObj +1 );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = ">>\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "stream\r\n";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    fgetpos( pf, &start );

    //
    //  write out buffer.
    //
    switch (qt.compression) {
      case COMPRESSION_CCITTFAX3:
      case COMPRESSION_CCITTFAX4:
        tiff_dumpTiffFAX( pf, qt ); // does not seem to work in all cases
        break;
      case COMPRESSION_PACKBITS:
        tiff_dumpTiffRLE( pf, qt );
        break;
      case COMPRESSION_CCITTRLE:
        tiff_dumpTiffCCITTRLE( pf, qt ); 

      case COMPRESSION_NONE:
      default:
        {
          tiff_dumpTiffRLE( pf, qt );
        }
        break;
    }
  
    fgetpos( pf, &end );
    czbuf = "\rendstream\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "endobj\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
  } catch(...)
  {
    throw -11;
  }

  return 1;
}

/****************************************************************************/
/*                                                                          */
/*  CDTPDFConvert::tiff_writePDFProcsetObject                               */
/*                                                                          */
/****************************************************************************/
int CDTPDFConvert::tiff_writePDFProcsetObject( FILE * pf, long nObj, QTiff & qt, fpos_t & start, fpos_t & end )
{
  try {
    CString czbuf;

    if(qt.m_bIsRGB)
      czbuf = "[ /PDF /ImageC ]\r";
    else if (qt.isFax())
      czbuf = "[ /PDF /ImageI ]\r";
    else
      czbuf = "[ /PDF /ImageI ]\r";

    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "endobj\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
  } catch(...) 
  {
    throw -12;
  }
  return 1;
}

/****************************************************************************/
/*                                                                          */
/*  CDTPDFConvert::tiff_writePDFContentsObject                              */
/*                                                                          */
/****************************************************************************/
int CDTPDFConvert::tiff_writePDFContentsObject( FILE * pf, long nObj, QTiff & qt, fpos_t & start, fpos_t & end )
{

  try {

    CString czbuf;
    double x_scale = 0;
    double y_scale = 0;
    CString czContentData;

    //
    //  Prepare the content data first.
    //
    x_scale = ( qt.width * 72 ) / qt.x_resolution;
    long tiff_width = (long)x_scale + (long)0.5;

    y_scale = ( qt.height * 72 ) / qt.y_resolution;
    long tiff_height = (unsigned long)( y_scale + 0.5);

    czContentData += "q\r";
    czbuf.Format( "%ld 0 0 %ld %ld %ld cm\r",tiff_width,tiff_height, 0, 0 );
    czContentData += czbuf;
    czbuf.Format( "/Im%lu Do\r",qt.page() );
    czContentData += czbuf;
    czContentData += "Q\r";

    //
    //  Write it all out.
    //
    czbuf = "<<\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Length %i\r", czContentData.GetLength() - 1 );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = ">>\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "stream\r\n";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    //
    //  content data
    //
    fwrite( (LPCSTR)czContentData, czContentData.GetLength(), 1, pf );

    czbuf = "endstream\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "endobj\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
  } catch (...)
  {
    throw -13;
  }

  return 1;
}

/****************************************************************************/
/*                                                                          */
/*  CDTPDFConvert::tiff_writePDFPageObject                                  */
/*                                                                          */
/****************************************************************************/
int CDTPDFConvert::tiff_writePDFPageObject( FILE * pf, long nObj, long pages_id , QTiff & qt )
{
  try {

    CString czbuf;

    double x_scale = 0;
    double y_scale = 0;


    //
    //  Prepare the content data first.
    //
    x_scale = ( qt.width * 72 ) / qt.x_resolution;
    long tiff_width = (long)x_scale + (long)0.5;

    y_scale = ( qt.height * 72 ) / qt.y_resolution;
    long tiff_height = (unsigned long)( y_scale + 0.5);


    czbuf = "<<\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "/Type /Page\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Parent %lu 0 R\r",pages_id );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/MediaBox [0 0 %ld %ld]\r",tiff_width,tiff_height);
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "/Resources\r<<\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    //
    // next obj must add length for  length == 2 objects
    //
    czbuf.Format( "/XObject << /Im%lu %lu 0 R >>\r",qt.page(), nObj + 3 ); 
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/ProcSet %lu 0 R \r", nObj + 2 );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = ">>\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Contents [%lu 0 R]\r>>\r", nObj + 1 ); //  next obj must add length for the contents == 1 objects
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "endobj\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
  } catch(...)
  {
    throw -14;
  }

  return 1;
}

/****************************************************************************/
/*                                                                          */
/*  CDTPDFConvert::tiff_writePDFPagesObject                                 */
/*                                                                          */
/****************************************************************************/
int CDTPDFConvert::tiff_writePDFPagesObject( FILE * pf, long nObj, QTiff & qt )
{

  try {

    long obj_per_image = 6; // just required entries. page,  contents, procset , ximage, length, 

    CString czbuf;

    //
    //Write Pages object.
    //
    czbuf = "<<\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );


    czbuf = "/Type /Pages\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Kids [%lu 0 R ", nObj +1 );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    long count = (long) (nObj + obj_per_image +1);
  
    //
    //  determine what objects the pages will be.
    //
    if (qt.pagecount() > 1) {
      for (int i = 1 ; i < qt.pagecount() ; i ++, count += obj_per_image ) {
        czbuf.Format( "%ld 0 R ", count );
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
      }
    }

    czbuf = "]\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Count %lu\r", (count-nObj) / obj_per_image );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/MediaBox [0 0 %ld %ld]\r",0,0);
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = ">>\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "endobj\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
  } catch(...)
  {
    throw -15;
  }

  return 1;
}

/****************************************************************************/
/*                                                                          */
/*  CDTPDFConvert::tiff_writePDFCatalogObject                               */
/*                                                                          */
/****************************************************************************/
int CDTPDFConvert::tiff_writePDFCatalogObject( FILE * pf, long nObj )
{
  try {

    CString czbuf;
    czbuf = "<<\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );


    czbuf = "/Type /Catalog\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format("/Pages %lu 0 R\r",nObj+1);
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = ">>\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "endobj\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
  } catch(...)
  {
    throw -16;
  }

  return 1;
}

/****************************************************************************/
/*                                                                          */
/*  CDTPDFConvert::tiff_writePDFInfoObject                                  */
/*                                                                          */
/****************************************************************************/
int CDTPDFConvert::tiff_writePDFInfoObject( FILE * pf, char* a_szCreator, char* a_szCreationDate,
                        char * a_szAuthor, char * a_szProducer, char * a_szTitle, char * a_szSubject, 
                        char * a_szKeywords  )
{
  try {

    CString czbuf;
    CString czdate;

    czbuf = "<<\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    CTime ctime = CTime::GetCurrentTime();

    czbuf.Format("/Creator (%s)\r", a_szCreator );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    if (a_szCreationDate == NULL)
      czbuf.Format("/CreationDate (%s)\r", ctime.Format( "%A, %B %d, %Y" ) );
    else
      czbuf.Format("/CreationDate (%s)\r", a_szCreationDate );

    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Author (%s)\r", a_szAuthor );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Producer (%s)\r", a_szProducer );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format( "/Title (%s)\r", a_szTitle );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format("/Subject (%s)\r", a_szSubject );
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf.Format("/Keywords (%s)\r", a_szKeywords);
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = ">>\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );

    czbuf = "endobj\r";
    fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1, pf );
  } catch(...)
  {
    throw -17;
  }

  return 1;
}

/****************************************************************************/
/*                                                                          */
/*  CDTPDFConvert::TiffToPdf                                                */
/*                                                                          */
/****************************************************************************/
int CDTPDFConvert::TiffToPdf( char* a_tiff, char* a_pdf, char* a_szCreator,  char* a_szCreationDate,
                        char * a_szAuthor, char * a_szProducer, char * a_szTitle, char * a_szSubject, 
                        char * a_szKeywords  )
{

  char szTiff[ 255 ];
  char szPdf[ 255 ];

  CString czbuf;
  
  long lCount = 0;
  long lLen = lstrlen( a_tiff );
  long nObj = 0;

  fpos_t start, end;

  memcpy( szTiff, a_tiff, lLen );
  szTiff[ lLen ] = '\0';

  if (a_pdf == NULL) {
    memcpy( szPdf, a_tiff, lLen );
    szPdf[ lLen - 3 ] = 'p';
    szPdf[ lLen - 2 ] = 'd';
    szPdf[ lLen - 1 ] = 'f';
    szPdf[ lLen ]  = '\0';
  } else {
    memcpy( szPdf, a_pdf, lstrlen( a_pdf ) );
    szPdf[ lstrlen( a_pdf ) ]  = '\0';
  }


  unsigned long info_id,pages_id, root_id;

  QTiff qt;

  try {
    if (qt.open( szTiff, NULL  )) {

      printf("Opended Image!\n");


      if (qt.photometric == PHOTOMETRIC_SEPARATED) {
        sprintf( m_szErrorCode, "CMYK File Format not accepted" );
        return 0;

      }

      FILE * pf = fopen( szPdf, "wb" );

      //
      //  Make sure we have enough space in the array.
      //
      fpos_t  * xref_arr = new fpos_t[ 255 + ( qt.pagecount() * 30) ];
      memset( xref_arr, 0, sizeof(fpos_t) * (255 + ( qt.pagecount() * 30 )) );

      if (pf) {

        //
        // If it is not a fax format then extract all bytes.
        //
        printf("Writing PDF Header.\n");
        //
        //  Need to track the size of the obj every write add the offset
        //
        czbuf = "%PDF-1.2\r";
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        //
        //  Write out info object
        //
        fgetpos( pf, &xref_arr[ nObj++ ] );
        info_id = nObj;
        czbuf.Format("%lu 0 obj\r",nObj);
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        tiff_writePDFInfoObject( pf, a_szCreator, a_szCreationDate,a_szAuthor,a_szProducer,a_szTitle,a_szSubject,a_szKeywords  );

        //
        // Write out catalog object
        //
        printf("Writing PDF catalog object.\n");

        fgetpos( pf, &xref_arr[ nObj++ ] );
        root_id = nObj;

        czbuf.Format("%lu 0 obj\r",nObj);
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        tiff_writePDFCatalogObject( pf, nObj );

        //
        //  Write out pages object
        //
        printf("Writing PDF pages object.\n");

        fgetpos( pf, &xref_arr[ nObj++ ] );
        pages_id = nObj;

        czbuf.Format("%lu 0 obj\r",nObj);
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        tiff_writePDFPagesObject( pf, nObj, qt);

        for ( int i = 0 ; i < qt.pagecount() ; i++ ) {
          if (qt.page() != i)
            qt.setpage( i );

          //
          //  Write out page object
          //
          printf("Writing PDF page %i object.\n", i);

          fgetpos( pf, &xref_arr[ nObj++ ] );
          czbuf.Format("%lu 0 obj\r",nObj);
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

          tiff_writePDFPageObject( pf, nObj, pages_id, qt );


          //
          // Write out contents object nobj + 1
          //
          printf("Writing PDF contents object.\n");

          fgetpos( pf, &xref_arr[ nObj++ ] );
          czbuf.Format("%lu 0 obj\r",nObj);
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

          tiff_writePDFContentsObject( pf, nObj, qt, start, end );

          //
          //  Write out procset
          //
          printf("Writing PDF procset object.\n");

          fgetpos( pf, &xref_arr[ nObj++ ] );
          czbuf.Format("%lu 0 obj\r",nObj);
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );
          tiff_writePDFProcsetObject( pf, nObj, qt, start, end );

          //
          //  Write out XObject
          //
          printf("Writing PDF XObject object.\n");

          fgetpos( pf, &xref_arr[ nObj++ ] );
          czbuf.Format("%lu 0 obj\r",nObj);
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );
          tiff_writePDFXObject( pf, nObj, qt, start, end );

          //
          //  Write out XObject Length
          //
          printf("Writing PDF XObject Length object.\n");

          fgetpos( pf, &xref_arr[ nObj++ ] );
          czbuf.Format("%lu 0 obj\r",nObj);
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );
          tiff_writePDFXObjectLength( pf, nObj, qt, start, end );

          //
          //  Write out Color Space Object
          //
          printf("Writing PDF Color Space object.\n");

          fgetpos( pf, &xref_arr[ nObj++ ] );
          czbuf.Format("%lu 0 obj\r",nObj);
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );
          if (tiff_writePDFColorSpace( pf, nObj, qt, start, end ) == 2) {
            //
            //  Need to dump out color space and length and stuff.
            //
            printf("Writing PDF Color Space info.\n");

            fgetpos( pf, &xref_arr[ nObj++ ] );
            czbuf.Format("%lu 0 obj\r",nObj);
            fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

            czbuf = "<<\r";
            fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

            czbuf.Format("/Length %lu 0 R\n", nObj + 1) ;
            fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

            czbuf = ">>\r";
            fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

            czbuf = "stream\r";
            fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );
            fgetpos( pf, &start );


            long count_colors = 1 << qt.bitspersample;

            QT_COLOR_MAP * colors = new QT_COLOR_MAP[ count_colors ];
            qt.FillColorMap( colors );

            for (int i = 0 ; i < count_colors ; i ++) {
              UCHAR r,g,b;
              r = colors[ i ].red;
              g = colors[ i ].green;
              b = colors[ i ].blue;

              fwrite( &r, sizeof( UCHAR ), 1 , pf );
              fwrite( &g, sizeof( UCHAR ), 1 , pf );
              fwrite( &b, sizeof( UCHAR ), 1 , pf );
            }

            delete[] colors;

            fgetpos( pf, &end );

            czbuf = "\rendstream\r";
            fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

            czbuf = "endobj\r";
            fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

            fpos_t offset = end - start;

            //
            //  write out colorspace length
            //
            fgetpos( pf, &xref_arr[ nObj++ ] );
            czbuf.Format("%lu 0 obj\r",nObj);
            fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );
            czbuf.Format("%lu\r", offset );
            fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );
            czbuf = "endobj\r";
            fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );
          }

        }

        //
        // Write Xref object.
        //
        printf("Writing PDF Xref object.\n");

        fgetpos( pf, &end );

        czbuf = "xref\r";
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        czbuf.Format( "0 %lu\r", nObj + 1 );
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );
     
        czbuf = "0000000000 65535 f \r";
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        for (i = 0; i < (long) nObj; i++) {
          czbuf.Format( "%010lu 00000 n \r",(unsigned long) xref_arr[ i ] );
          fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );
          fgetpos( pf, &start );
        }

        czbuf = "trailer\r";
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        czbuf = "<<\r";
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        czbuf.Format( "/Size %lu\r", nObj+1 );
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        czbuf.Format( "/Root %lu 0 R\r",root_id);
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        czbuf.Format( "/Info %lu 0 R\r",info_id);
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        czbuf = ">>\r";
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );


        czbuf = "startxref\r";
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        czbuf.Format( "%lu\r",(unsigned long)end );
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        czbuf = "%%EOF\r";
        fwrite( (LPCSTR)czbuf, czbuf.GetLength(), 1 , pf );

        fclose( pf );
      }

      delete[] xref_arr;

    } else {
      strcpy( m_szErrorCode, "Unable to open file." );
      return -1;  // Unable to open file.
    }
  } catch ( int err ) {

    char szFunction[ 50 ];

    switch( err )
    {
      case -10:
        strcpy( szFunction, "tiff_writePDFXObjectLength" );
        break;
      case -11:
        strcpy( szFunction, "tiff_writePDFXObject" );
        break;
      case -12:
        strcpy( szFunction, "tiff_writePDFProcsetObject" );
        break;
      case -13:
        strcpy( szFunction, "tiff_writePDFContentsObject" );
        break;
      case -14:
        strcpy( szFunction, "tiff_writePDFPageObject" );
        break;
      case -15:
        strcpy( szFunction, "tiff_writePDFPagesObject" );
        break;
      case -16:
        strcpy( szFunction, "tiff_writePDFCatalogObject" );
        break;
      case -17:
      default:
        strcpy( szFunction, "tiff_writePDFInfoObject" );
        break;
    }
    sprintf( m_szErrorCode, "Error in function %s", szFunction );
    return err;
    
  } catch (...) {
    // error in this function
    strcpy( m_szErrorCode, "Error in convertTiffToPdf" );
    return 0;
  }

  return 1;
}
