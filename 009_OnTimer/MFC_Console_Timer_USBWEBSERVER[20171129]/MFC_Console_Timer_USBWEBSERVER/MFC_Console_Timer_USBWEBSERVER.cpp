// MFC_Console_Timer_USBWEBSERVER.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "MFC_Console_Timer_USBWEBSERVER.h"
//========================
#include <windows.h>
#include <afxpriv.h>
#include <Wininet.h>
#include <iostream>
#include<fstream>//7
#include <stdio.h>
#include <stdlib.h> //srand() ,rand() ,system()
#include <time.h>   //time()
#include <atlbase.h>
#include <afxtempl.h>//CArray Step_01 
using namespace std;
//========================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//===============
extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow();//取得視窗API宣告
void CALLBACK TimeProc(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime);//TIMER函數宣告

// 僅有的一個應用程式物件

CWinApp theApp;

using namespace std;
int intTimerCount = 0;
int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);
	intTimerCount = 0;
    if (hModule != nullptr)
    {
        // 初始化 MFC 並於失敗時列印錯誤
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 配合您的需要變更錯誤碼
            wprintf(L"嚴重錯誤: MFC 初始化失敗\n");
            nRetCode = 1;
        }
        else
        {
			// TODO: code your application's behavior here.
			CString strHello;
			strHello="start";
			cout << (LPCTSTR)strHello << endl;

			//HWND hWnd = ::GetConsoleWindow();//取得視窗HAND
			//::ShowWindow(hWnd, SW_MINIMIZE);//縮小視窗
			ShellExecute(NULL, L"open", L"C:\\Users\\Administrator\\Desktop\\Tool\\USBWebserver_v8.6\\usbwebserver.exe", NULL, NULL, SW_SHOWNORMAL);

			SetTimer(NULL, 1, 90000, TimeProc);//啟動TIMER
			MSG   msg;
			while (GetMessage(&msg, NULL, 0, 0)) //事件回應區
			{
				if (msg.message == WM_TIMER)
				{
					DispatchMessage(&msg);
				}
			}
        }
    }
    else
    {
        // TODO: 配合您的需要變更錯誤碼
        wprintf(L"嚴重錯誤: GetModuleHandle 失敗\n");
        nRetCode = 1;
    }

    return nRetCode;
}
void CALLBACK TimeProc(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime)
{
	//=========================
	bool blncheckWebport = true;
	CTime timeNow = CTime::GetCurrentTime();
	CString StrTime;
	StrTime = timeNow.Format("%Y/%m/%d %H:%M:%S");

	FILE *pf;
	USES_CONVERSION;

	if ((intTimerCount % 2) == 0)//180秒判斷一次
	{
		pf = NULL;
		pf = fopen("jashlog.txt", "a");

		intTimerCount = 0;
		DWORD dwFlags;
		dwFlags = 0;
		
		CString StrUrl;
		StrUrl.Format(L"http://149.56.83.152?data=%s", timeNow.Format("%Y%m%d%H%M%S"));
		blncheckWebport = InternetCheckConnection(StrUrl, FLAG_ICC_FORCE_CONNECTION, dwFlags);
		
		if (blncheckWebport)
		{
			fprintf(pf, "%s-check 80 port OK\n", T2A((LPTSTR)(LPCTSTR)StrTime));
		}
		else
		{
			fprintf(pf, "%s-check 80 port fail\n", T2A((LPTSTR)(LPCTSTR)StrTime));
		}

		fclose(pf);
	}
	if (!blncheckWebport)
	{
		pf = NULL;
		pf = fopen("jashlog.txt", "a");
		
		HWND hWnd0 = FindWindow(NULL, L"USBWebserver");
		while (hWnd0 != NULL)
		{
			SendMessage(hWnd0,WM_CLOSE, 0, 0);//關閉視窗
			Sleep(100);
			hWnd0 = FindWindow(NULL, L"USBWebserver");
			fprintf(pf, "%s-close\n", T2A((LPTSTR)(LPCTSTR)StrTime));
		}

		Sleep(200);
		ShellExecute(NULL, L"open", L"C:\\Users\\Administrator\\Desktop\\Tool\\USBWebserver_v8.6\\usbwebserver.exe", NULL, NULL, SW_SHOWNORMAL);
		fprintf(pf, "%s-Reload\n", T2A((LPTSTR)(LPCTSTR)StrTime));

		fclose(pf);
	}
	intTimerCount++;
}