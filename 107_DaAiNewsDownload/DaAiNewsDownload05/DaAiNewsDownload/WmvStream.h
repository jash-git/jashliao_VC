#pragma once
#include <wmsdk.h>


#ifndef SAFE_RELEASE

#define SAFE_RELEASE( x )  \
    if ( NULL != x )       \
    {                      \
        x->Release( );     \
        x = NULL;          \
    }

#endif
#ifndef SAFE_ARRAYDELETE
#define SAFE_ARRAYDELETE( x )  \
    if( NULL != x )        \
    {                      \
        delete [] x;       \
        x = NULL;          \
    }
#endif
#ifndef DibNumberColors
	#define DibNumColors( lpbi ) ( ( lpbi )->biClrUsed == 0 && ( lpbi )->biBitCount <= 8 ) ? (( int )( 1 << ( int )( lpbi )->biBitCount ))  : (( int )(( lpbi )->biClrUsed )) 
#endif

#ifndef DibPaletteSize
	#define DibPaletteSize( lpbi ) ( DibNumColors( lpbi ) * sizeof( RGBQUAD ) ) 
#endif
#ifndef BFT_BITMAP
	#define BFT_BITMAP 0X4D42
#endif


class CWmvStream
{
public:
	CWmvStream();
	~CWmvStream(void);

private:

	IWMSyncReader* m_ISyncReader;// opens the file and gets all its properties
		// this is an INSSBuffer (an Interface)  that when reading from a stream gets the data, then there is another step to retrive the daa from this Interfaced buffer
	INSSBuffer* m_pINSSBuffer;
	// this interface can receive the properties of a specific output in the wmv file
	IWMOutputMediaProps* m_IVideoOutputProps;
	WM_MEDIA_TYPE* m_theMediaType;
	// this struct would hold the information about the bitmaps extracted from the video stream
	BITMAPINFOHEADER m_BitmapInfoHdr;
	WMVIDEOINFOHEADER m_theVideoInfoHeader;
	// this is the original bitmap extracted from the file, the gray is m_grayBitmapBuffer
	BYTE* m_bitmapBuffer;
	// this contains the original(no manipulations straight from the file)  bitmapBuffer length
	DWORD m_dwrdBitmapBufferLength;
	HRESULT hr;
	DWORD m_theOutputsCount;
	int m_iVideoOutputNumber;
	int m_iAudioOutputNumber;
	int m_iVideoStreamNumber;
	int m_iAudioStreamNumber;
	CString m_filename;
	QWORD m_qwTotalTimeInSeconds;
	QWORD m_qwCurrrentPostionInSeconds;
	int m_iFramesRead;
	bool m_isStreamOpen;
	bool m_OpenSuccesfully;
public:
	
	bool OpenStream(CString filename);
	void CloseStream();
	int NextFrame();
	unsigned char* GetColorData() const {return m_bitmapBuffer;}
	BITMAPINFOHEADER GetBitmapInfoHeader() {return m_BitmapInfoHdr; }
	unsigned int GetSizeX() {return m_BitmapInfoHdr.biWidth;}
	unsigned int GetSizeY() {return m_BitmapInfoHdr.biHeight;}
	QWORD GetTotalTimeInSeconds() {return m_qwTotalTimeInSeconds;}
	QWORD GetCurrentPostionInSeconds() {return m_qwCurrrentPostionInSeconds;}
	int GetFramesRead() {return m_iFramesRead;}
	bool IsStreamOpen() {return m_isStreamOpen;}
	int SaveCurrentFrameToBmp(char* filename);
	
};
