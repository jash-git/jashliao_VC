#pragma once
#include <GdiPlus.h>

using namespace Gdiplus;

class Utility
{
public:
	Utility(void);
	~Utility(void);

public:
	static CString GetTempPathx();
	static CString GetMoudulePath();
	static void ShowPhoto(HWND hWnd, CRect & rc, BYTE * pBmpData, int nLen);

	static Bitmap* CreateBitmapFromMemory(const void *buf, size_t size);
	static bool mem_to_global(const void *buf, size_t size, HGLOBAL global);
};
