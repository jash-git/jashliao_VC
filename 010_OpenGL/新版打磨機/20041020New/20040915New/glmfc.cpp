#include "stdafx.h"
#include <gl/gl.h>
#include <gl/glu.h>
BYTE m_1to8[2] = {0, 255};
BYTE m_2to8[4] = {0, 0x55, 0xaa, 0xff};
BYTE m_3to8[8] = {0, 0111>>1, 0222>>1, 0333>>1, 0444>>1, 0555>>1, 0666>>1, 0377};

int	m_defaultOverride[13] = {0, 3, 24, 27, 64, 67, 88, 173, 181, 236, 247, 164, 91};
PALETTEENTRY m_defaultPalEntry[20] = 
{
	{0,    0,    0,    0},	// 0
	{0x80, 0,    0,    0},
	{0,    0x80, 0,    0},
	{0x80, 0x80, 0,    0},
	{0,    0,    0x80, 0},
	{0x80, 0,    0x80, 0},
	{0,    0x80, 0x80, 0},
	{0xC0, 0xC0, 0xC0, 0},	// 7

	{192,  220,  192,  0},	// 8
	{166,  202,  240,  0},
	{255,  251,  240,  0}, 
	{160,  160,  164,  0},	// 11

	{0x80, 0x80, 0x80, 0},	// 12
	{0xFF, 0,    0,    0}, 
	{0,    0xFF, 0,    0}, 
	{0xFF, 0xFF, 0,    0}, 
	{0,    0,    0xFF, 0}, 
	{0xFF, 0,    0xFF, 0},
	{0,    0xFF, 0xFF, 0}, 
	{0xFF, 0xFF, 0xFF, 0}	// 19
};
	
BYTE ComponentFromIndex(int i, UINT nbits, UINT shift)
{
	BYTE val;
	val = (BYTE)(i>>shift);
	switch(nbits)
	{
	case 1:
		val &= 0x1;
		return m_1to8[val];
	case 2:
		val &= 0x3;
		return m_2to8[val];
	case 3:
		val &= 0x7;
		return m_3to8[val];
	}
	return 0;
}

BOOL CreateRGBPalette(HDC hDC, CPalette * &pPal)
{
	//
	// check to see if we need a palette
	//
	PIXELFORMATDESCRIPTOR	pfd;

	int n = GetPixelFormat(hDC);
	DescribePixelFormat(hDC, n, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	if(FALSE == (pfd.dwFlags & PFD_NEED_PALETTE))
		return FALSE;

	//
	// allocate a log pal and fill it with the color table info
	//
	TRACE0(_T("creating palette.\r\n"));
	LOGPALETTE * pLogPal = (LOGPALETTE *)malloc(sizeof(LOGPALETTE)+256*sizeof(PALETTEENTRY));
	if(NULL == pLogPal)
	{
		TRACE(_T("out of memory for logpal.\r\n"));
		return FALSE;
	}
	pLogPal->palNumEntries = 256;	// table size
	pLogPal->palVersion	= 0x300;	// Windows 3.0
	//
	// create RGB Palette
	//
	ASSERT(8==pfd.cColorBits);
	n = 1<<pfd.cColorBits;
	for(int i=0; i<n; ++i)
	{
		pLogPal->palPalEntry[i].peBlue = ComponentFromIndex(i, pfd.cBlueBits, pfd.cBlueShift);
		pLogPal->palPalEntry[i].peFlags = 0;
		pLogPal->palPalEntry[i].peGreen = ComponentFromIndex(i, pfd.cGreenBits, pfd.cGreenShift);
		pLogPal->palPalEntry[i].peRed = ComponentFromIndex(i, pfd.cRedBits, pfd.cRedShift);
	}
	//
	// fix up color table with system colors
	//
	if((2 == pfd.cBlueBits)&&(6 == pfd.cBlueShift)&&(8 == pfd.cColorBits)&&(3 == pfd.cGreenBits)&&(3 == pfd.cGreenShift)&&(3 == pfd.cRedBits)&&(0 == pfd.cRedShift))
	{
		for(int j = 1; j <= 12; ++j)
			pLogPal->palPalEntry[m_defaultOverride[j]] = m_defaultPalEntry[j];
	}

	// delete any existing GDI palette
	free(pPal);
	pPal = new CPalette;
	BOOL bResult = pPal->CreatePalette(pLogPal);
	free(pLogPal);

	return bResult;
}

