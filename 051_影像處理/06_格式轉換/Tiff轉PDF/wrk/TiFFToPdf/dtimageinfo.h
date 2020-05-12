//************************
//*                      *
//*  Copyright (C) 2000  *
//*                      *
//*  chris rubio         *
//*                      *
//*  dtimageinfo.h
//************************
//****************************************************************************
//*                              REVISION HISTORY                            *
//****************************************************************************
//*   Date   *                                                     *   Who   *
//****************************************************************************
//* 12/5/2002* Created header file.                                *   CLR   *
//****************************************************************************
#ifndef DTIMAGEINFO_H
#define DTIMAGEINFO_H

#include <math.h>


#define CVT(x)			(((x) * 255L) / ((1L<<16)-1))
#define	SCALE(x)		(((x)*((1L<<16)-1))/255)
#define CalculateLine(width,bitdepth)	(((width * bitdepth) + 7) / 8)
#define CalculatePitch(line)	(line + 3 & ~3)

// needed for png & gif
struct rgb_color_struct { BYTE r,g,b; };
// needed for png & mng
#define COLORTYPE_PALETTE	1
#define COLORTYPE_COLOR		2
#define COLORTYPE_ALPHA		4

#define RGB2GRAY(r,g,b) ((b*11 + g*59 + r*30)/100) //color to grey mapping


typedef struct tagQTImageInfo {
  DWORD   dwEffWidth;           // DWORD aligned scan line width
  BYTE *  pImage;               // THE IMAGE BITS
  void*   pGhost;               // if this is a ghost, pGhost point to the body
  long    nFrame;        
  long    nNumFrames;       
  RECT    rSelectionBox;        // bounding rectangle
  BYTE    nAlphaMax;            // max opacity (fade)
  BYTE    bAlphaPaletteEnabled; // true if alpha values in the palette are enabled.
	BYTE	  bColorType;			      
  long    xDPI;                 // horizontal resolution
  long    yDPI;                 // vertical resolution
  long    xOffset;
  long    yOffset;
} QT_IMAGE_INFO;

typedef struct tagQT_COLOR_MAP
{
  DWORD red;
  DWORD green;
  DWORD blue;
} QT_COLOR_MAP;


class QTiff
{
  public:

   QTiff();
  ~QTiff(){ close(); };

  int open( char* szTiff, char * szMode );
  void close();
  long pagecount();
  void setpage( long a_lPage ) { TIFFSetDirectory(m_tif,(uint16)a_lPage); getdata(); m_lPage = a_lPage; }
  long page() { return m_lPage; }
  void getdata();
  int DecompressImage();
  int isFax();
  void * Create( DWORD a_dwWidth, DWORD a_dwHeight, long a_wBpp );
  void SetPaletteIndex( BYTE idx, BYTE r, BYTE g, BYTE b, BYTE alpha );

  int FillColorMap( QT_COLOR_MAP * a_in );

  TIFF * m_tif;
  uint32 height;
  uint32 width;
  uint16 bitspersample;
  uint16 samplesperpixel;
  uint32 rowsperstrip;
  uint16 photometric;
  uint16 compression;
  uint16 orientation;
  uint32 x, y;
  float x_resolution;
  float y_resolution;
  float x_offset;
  float y_offset;

  FILE hFile;  // file handle to read the image

  long m_lPageCount;
  long m_lPage;
  BOOL m_bIsRGB;

  QT_IMAGE_INFO       m_info;
  BITMAPINFOHEADER    m_head; 
  BYTE  *             m_pbSelection;  // selected region
  BYTE  *             m_pbAlpha;      // alpha channel
  void  *             m_pDib;         // contains the header, the palette, the pixels

};


#endif
