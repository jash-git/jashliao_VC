// CreateProcessCallCmd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CreateProcessCallCmd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
TCHAR gstrCurDrt[500];//存放目其目錄字串

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

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
		int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
		if( gstrCurDrt[nLen]!='\\' )
		{
			gstrCurDrt[nLen++] = '\\';
			gstrCurDrt[nLen] = '\0';
		}
		CString StrCallExeName;
		StrCallExeName=gstrCurDrt;
		StrCallExeName+="SearchFileCmd.exe ";
		StrCallExeName+="C:\\test";
		StrCallExeName+=" ";
		StrCallExeName+="test_";
		PROCESS_INFORMATION pi;
		STARTUPINFO si;
		memset(&si,0,sizeof(si));
		si.cb=sizeof(si);
		si.wShowWindow=SW_MINIMIZE;
		si.dwFlags=STARTF_USESHOWWINDOW;
		BOOL fRet=CreateProcess(NULL,
								StrCallExeName.GetBuffer(0),
								NULL,
								NULL,
								FALSE,
								NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,
								NULL,
								NULL,
								&si,
								&pi);
		if(fRet)
		{
			WaitForSingleObject(pi.hProcess,INFINITE);
		}
	}

	return nRetCode;
}


