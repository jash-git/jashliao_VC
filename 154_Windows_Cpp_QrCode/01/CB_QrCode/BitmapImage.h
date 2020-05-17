#ifndef __BITMAP_IMAGE_LOADER_H__
#define __BITMAP_IMAGE_LOADER_H__

#include <string>

class CBitmapImage
{
public:

    // Constructor
    CBitmapImage();

    // Constructor
    CBitmapImage( unsigned char* pImgData,
                  int            nImgWidth,
                  int            nImgHeight,
                  int            nImgRowDist );

    // Destructor
    ~CBitmapImage();

    // Attach an image to class instance
    void Attach( unsigned char* pImgData,
                 int            nImgWidth,
                 int            nImgHeight,
                 int            nImgRowDist );

    // Detach attached image
    void Detach();

    // Load bitmap (BMP) file with 8bpp
    int Load8bppBitmap( std::string strFileName );

    // Load bitmap (BMP) file with 8bpp
    int Load8bppBitmap( const char* pchFileName );

    // Save bitmap (BMP) file with 8bpp
    int Save8bppBitmap( std::string strFileName );

    // Save bitmap (BMP) file with 8bpp
    int Save8bppBitmap( const char* pchFileName );


    // Release an image
    void Release();

    // Get image attributes
    inline int            GetWidth()       { return m_nImgWidth;   }
    inline int            GetHeight()      { return m_nImgHeight;  }
    inline int	          GetRowByteDist() { return m_nImgRowDist; }
    inline unsigned char* GetDataPtr()     { return m_pImgData;    }


protected:

    // Image attributes
    unsigned char* m_pImgData;
    int            m_nImgWidth;
    int            m_nImgHeight;
    int            m_nImgRowDist;
};

#endif // __BITMAP_IMAGE_LOADER_H__
