// CString2CTime.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "CString2CTime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 僅有的一個應用程式物件

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// 初始化 MFC 並於失敗時列印錯誤
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 配合您的需要變更錯誤碼
		_tprintf(_T("嚴重錯誤: MFC 初始化失敗\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: 在此撰寫應用程式行為的程式碼。
		CString ShowData;
		COleVariant vtime;
		COleDateTime time4;
		SYSTEMTIME systime;
		ShowData=L"2011-10-11 18:00:00";
		vtime=ShowData;  
		vtime.ChangeType(VT_DATE);   
		time4=vtime;
		VariantTimeToSystemTime(time4,&systime);
		CTime ct;
		ct=systime;
		ShowData=ct.Format(L"%Y-%m-%d_%H:%M:%S");
	}

	return nRetCode;
}
