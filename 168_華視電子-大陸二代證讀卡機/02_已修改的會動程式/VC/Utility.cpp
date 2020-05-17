#include "stdafx.h"
#include "Utility.h"

Utility::Utility(void)
{
}

Utility::~Utility(void)
{
}

CString Utility::GetTempPathx()
{
	CString strPathBase(_T(""));
	TCHAR sztempdirectory[MAX_PATH];

	int i = GetTempPath(MAX_PATH - 1, sztempdirectory);
	if (sztempdirectory[i - 1] != _T('\\'))
	{
		lstrcat(sztempdirectory, _T("\\"));

	}
	CString strTempdirectory(sztempdirectory);
	strPathBase = strTempdirectory + _T("chinaidcard\\");
	CreateDirectory(strPathBase, NULL);
	return strPathBase;
}

CString Utility::GetMoudulePath()
{
	CString strRetun = L"";

	HMODULE module = AfxGetInstanceHandle();
	if (module == NULL)
	{
		return _T("");
	}
	wchar_t szBuff[MAX_PATH];
	GetModuleFileName(module, szBuff, sizeof(szBuff));

	wchar_t acBuf[200];
	GetShortPathName(szBuff, acBuf, 200);
	wchar_t acText[200];
	GetLongPathName(acBuf, acText, 200);

	CString strTemp(acBuf);
	strTemp = acText;
	int n = strTemp.ReverseFind('\\');
	strRetun = strTemp.Mid(0, n);

	return strRetun;
}

bool Utility::mem_to_global(const void *buf, size_t size, HGLOBAL global)  
{  
	void *dest = GlobalLock( global );  
	if( NULL == dest )  
	{  
		return false;  
	}  
	memcpy( dest, buf, size );  
	GlobalUnlock( global );  
	return true;  
} 

Bitmap* Utility::CreateBitmapFromMemory(const void *buf, size_t size)
{  
	IStream *stream = NULL;  
	HGLOBAL global = GlobalAlloc( GMEM_MOVEABLE, size );  
	if( NULL == global )  
		return NULL;  
	/* copy the buf content to the HGLOBAL */  
	if( !mem_to_global( buf, size, global ) )  
	{  
		GlobalFree( global );  
		stream->Revert();  

		return NULL;  
	}  
	/* get the IStream from the global object */  
	if( CreateStreamOnHGlobal( global, true, &stream ) != S_OK )  
	{  
		GlobalFree( global );  
		stream->Revert();  
		return NULL;  
	}  
	/* create the image from the stream */  
	Bitmap *image = Bitmap::FromStream( stream, FALSE );  
	//stream->Release();  
	//stream->Revert();  
	stream = NULL;  
	/* I suppose when the reference count for stream is 0, it will  
	GlobalFree automatically. The Image maintain the object also.*/   
	return image;  
}

void Utility::ShowPhoto(HWND hWnd, CRect & rc, BYTE * pBmpData, int nLen)
{
	Graphics graph(hWnd);

	Bitmap * pBmp = CreateBitmapFromMemory(pBmpData, nLen);
	if (pBmp)
	{
		graph.DrawImage(pBmp, rc.left, rc.top, pBmp->GetWidth(), pBmp->GetHeight(), pBmp->GetWidth(), pBmp->GetHeight(), UnitPixel);
		delete pBmp;
	}
}
