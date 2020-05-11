// GetFileSize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GetFileSize.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
DWORD GetFileSize(CString filepath) 
{
    WIN32_FIND_DATA fileInfo;
    HANDLE hFind;
    DWORD fileSize;
    CString filename;
    filename = filepath;
    hFind = FindFirstFile(filename,&fileInfo);
    if(hFind != INVALID_HANDLE_VALUE)
        fileSize = fileInfo.nFileSizeLow;
    
    FindClose(hFind); 
    return fileSize;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		strHello="c:\\s130603162.mp4";
		cout << (LPCTSTR)strHello <<" size= " << GetFileSize(strHello) <<endl;
	}

	return nRetCode;
}


