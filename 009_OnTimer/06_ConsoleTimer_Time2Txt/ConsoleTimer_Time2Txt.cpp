// ConsoleTimer_Time2Txt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConsoleTimer_Time2Txt.h"
//========================
#include <windows.h>

#include <iostream>
#include<fstream>//7
#include <stdlib.h> //srand() ,rand() ,system()
#include <time.h>   //time()
#include <atlbase.h>
#include <afxtempl.h>//CArray Step_01 
using namespace std;
//========================
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//===============
extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow ();//取得視窗API宣告
void CALLBACK TimeProc( HWND hwnd, UINT message, UINT idTimer, DWORD dwTime);//TIMER函數宣告
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
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;

		HWND hWnd = ::GetConsoleWindow();//取得視窗HAND
		::ShowWindow( hWnd, SW_MINIMIZE );//縮小視窗

		SetTimer(NULL,1,30000,TimeProc);//啟動TIMER
		MSG   msg;   
		while(GetMessage(&msg,NULL,0,0)) //事件回應區
		{   
			if(msg.message==WM_TIMER)   
			{   
				DispatchMessage(&msg);   
			}
		}
	}

	return nRetCode;
}

void CALLBACK TimeProc( HWND hwnd, UINT message, UINT idTimer, DWORD dwTime)   
{
		//=========================
		CTime timeNow=CTime::GetCurrentTime();
		CString StrTime;
		FILE *pf;
		StrTime=timeNow.Format("%Y%m%d%H%M%S");
		pf=fopen("time.log","a");
		fprintf(pf,"%s\n",StrTime.GetBuffer(0));
		fclose(pf);
}
