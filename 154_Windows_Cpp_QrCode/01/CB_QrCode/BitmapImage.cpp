#include <fstream>
#include<string.h>
#include "BitmapImage.h"


//////////////////////////////////////////////////////////////////////////////
//
//  Copied (with minor changes) from wingdi.h
//
//////////////////////////////////////////////////////////////////////////////

typedef unsigned short WORD;
typedef unsigned long  DWORD;
typedef long           LONG;
typedef unsigned char  BYTE;

// Unsupported GCC compiler feature (for default NetBSD target)
#pragma pack( push, 2 )

typedef struct tagBITMAPFILEHEADER {
        WORD    bfType;
        DWORD   bfSize;
        WORD    bfReserved1;
        WORD    bfReserved2;
        DWORD   bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
        DWORD      biSize;
        LONG       biWidth;
        LONG       biHeight;
        WORD       biPlanes;
        WORD       biBitCount;
        DWORD      biCompression;
        DWORD      biSizeImage;
        LONG       biXPelsPerMeter;
        LONG       biYPelsPerMeter;
        DWORD      biClrUsed;
        DWORD      biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD {
        BYTE    rgbBlue;
        BYTE    rgbGreen;
        BYTE    rgbRed;
        BYTE    rgbReserved;
} RGBQUAD;

// Unsupported GCC compiler feature (for default target) under NetBSD
#pragma pack( pop )


// Constructor
CBitmapImage::CBitmapImage( unsigned char* pImgData,
                            int            nImgWidth,
                            int            nImgHeight,
                            int            nImgRowDist )
{
    Attach( pImgData, nImgWidth, nImgHeight, nImgRowDist );
}

// Constructor
CBitmapImage::CBitmapImage()
{
    m_pImgData    = NULL;
    m_nImgWidth   = 0;
    m_nImgHeight  = 0;
    m_nImgRowDist = 0;
}

// Destructor
CBitmapImage::~CBitmapImage()
{
    Release();
}

// Release an image
void CBitmapImage::Attach( unsigned char* pImgData,
                           int            nImgWidth,
                           int            nImgHeight,
                           int            nImgRowDist )
{
    m_pImgData    = pImgData;
    m_nImgWidth   = nImgWidth;
    m_nImgHeight  = nImgHeight;
    m_nImgRowDist = nImgRowDist;
}

// Detach attached image
void CBitmapImage::Detach()
{
    m_pImgData    = NULL;
    m_nImgWidth   = 0;
    m_nImgHeight  = 0;
    m_nImgRowDist = 0;
}

// Release an image
void CBitmapImage::Release()
{
    if( m_pImgData != NULL )
        delete []m_pImgData;

    m_pImgData    = NULL;
    m_nImgWidth   = 0;
    m_nImgHeight  = 0;
    m_nImgRowDist = 0;
}


// Load bitmap (BMP) file with 8bpp
int CBitmapImage::Load8bppBitmap( std::string strFileName )
{
    return Load8bppBitmap( strFileName.c_str() );
}


// Load bitmap (BMP) file with 8bpp
int CBitmapImage::Load8bppBitmap( const char* pchFileName )
{
    setlocale( LC_ALL, "" );

    std::ifstream hFile;
    hFile.open( pchFileName, std::ios::binary );

    if( ! hFile.is_open() )
        return -1;

    BITMAPFILEHEADER bmfh;

    hFile.read( (char *)&bmfh, sizeof( bmfh ) );
    if( hFile.fail() )
        return -1;

    if( bmfh.bfType != 0x4D42 )
        return -1;

    struct
    {
        BITMAPINFOHEADER bmih;
        RGBQUAD          rgbqPalette[ 256 ];
    } bmInfo;

    hFile.read( (char *)&bmInfo.bmih, sizeof( BITMAPINFOHEADER ) );
    if( hFile.fail() )
        return -1;

    if( bmInfo.bmih.biBitCount != 8 )
        return -1;

    m_nImgWidth   = m_nImgRowDist = (int)bmInfo.bmih.biWidth;
    m_nImgHeight  = (int)bmInfo.bmih.biHeight;
    m_nImgRowDist = ( m_nImgWidth + 3 ) &~ 3;

    hFile.read( (char *)&bmInfo.rgbqPalette, 256 * sizeof( RGBQUAD ) );
    if( hFile.fail() )
        return -1;

    Release();

    if( !( m_pImgData = new BYTE[ m_nImgRowDist * m_nImgHeight ] ) )
        return -1;

    hFile.read( (char *)m_pImgData, m_nImgRowDist * m_nImgHeight );
    if( hFile.fail() )
        return -1;

    hFile.close();

    unsigned char btTones[ 256 ];
    for( int i = 0; i < 256; ++i )
    {
        btTones[ i ] = ( bmInfo.rgbqPalette[ i ].rgbRed   +
                         bmInfo.rgbqPalette[ i ].rgbGreen +
                         bmInfo.rgbqPalette[ i ].rgbBlue  ) / 3;
    }

    unsigned long ulPixelsCnt = m_nImgRowDist * m_nImgHeight;

    for( unsigned long ul = 0; ul < ulPixelsCnt; ++ul )
        m_pImgData[ ul ] = btTones[ m_pImgData[ ul ] ];

    BYTE* pRowDataPtr = new BYTE[ m_nImgRowDist ];

    for( int nRow = 0; nRow < m_nImgHeight / 2; nRow++ )
    {
        memcpy( pRowDataPtr,
                &m_pImgData[ nRow * m_nImgRowDist ],
                 m_nImgRowDist );

        memcpy( &m_pImgData[ nRow * m_nImgRowDist ],
                &m_pImgData[ ( m_nImgHeight - nRow - 1 ) * m_nImgRowDist ],
                 m_nImgRowDist );

        memcpy( &m_pImgData[ ( m_nImgHeight - nRow - 1 ) * m_nImgRowDist ],
                 pRowDataPtr,
                 m_nImgRowDist );
    }

    delete []pRowDataPtr;

    return 0;
}

// Save bitmap (BMP) file with 8bpp
int CBitmapImage::Save8bppBitmap( std::string strFileName )
{
    return Save8bppBitmap( strFileName.c_str() );
}


// Save bitmap (BMP) file with 8bpp
int CBitmapImage::Save8bppBitmap( const char* pchFileName )
{
    setlocale( LC_ALL, "" );

    std::ofstream fOut;

    fOut.open( pchFileName, std::ios::binary );
    if( !fOut.is_open() )
        return -1;

    BITMAPFILEHEADER bmfh =
    {
        'B'| ( 'M' << 8 ),
        m_nImgRowDist * m_nImgHeight + 1078,
        0,
        0,
        1078
    };


   fOut.write( (char*)&bmfh, sizeof( bmfh ) );
   if( fOut.fail() )
       return -1;

    BITMAPINFOHEADER bmih =
    {
        40,
        m_nImgWidth,
        m_nImgHeight,
        1,
        8,
        0,
        0,
        0,
        0,
        0,
        0
    };

    fOut.write( (char*)&bmih, sizeof( BITMAPINFOHEADER ) );
    if( fOut.fail() )
        return -1;

    RGBQUAD rgbqPal[ 256 ];
    for( int nIntens = 0; nIntens < 256; nIntens++ )
    {
        rgbqPal[ nIntens ].rgbRed      = nIntens;
        rgbqPal[ nIntens ].rgbGreen    = nIntens;
        rgbqPal[ nIntens ].rgbBlue     = nIntens;
        rgbqPal[ nIntens ].rgbReserved = 0;
    }

    fOut.write( (char*)rgbqPal, 256 * sizeof( RGBQUAD ) );
    if( fOut.fail() )
        return -1;

    BYTE* pBitmap = new BYTE[ m_nImgRowDist * m_nImgHeight ];
    if( pBitmap == NULL )
        return -1;

    unsigned char* pData = (unsigned char*)m_pImgData;

    for( int iTop = 0, iBottom = m_nImgHeight - 1; iTop < m_nImgHeight; iTop++, iBottom-- )
    {
        memcpy( &pBitmap[ iTop * m_nImgRowDist], &pData[ iBottom * m_nImgRowDist ], m_nImgRowDist );
    }

    fOut.write( (char*)pBitmap, m_nImgRowDist * m_nImgHeight );
    if( fOut.fail() )
        return -1;

    delete []pBitmap;

    fOut.close();

    return 0;
}
