// VLC_Open_Move_Cmd.cpp : Defines the entry point for the console application.
//////////////////////////////////////////////////////////////
//
//	檔案功能說明:建立一支可以呼叫可攜版VLC和指定該VLC位置與視窗大小的命令模式程式
//	最後修改日期:2013/02/01
//	撰寫人:jash.liao
//
/////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VLC_Open_Move_Cmd.h"

//----------------------------
//為了字串轉數字的函數宣告
#include<stdio.h>
#include <stdlib.h>
//----------------------------

//----------------------------
//為了C++讀檔的函數宣告
#include<iostream>
#include<fstream>

using namespace std;
//----------------------------

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
//============================================================
//
//主函數:包含所有動作
//
//============================================================
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
	//----------------------------
	//為了C++讀檔變數宣告
		char chrData01[500];
		char chrData02[500];
		char chrData03[500];
		char chrData04[500];
	//----------------------------

	//----------------------------
	//為了C++讀檔
		fstream a;
		a.open("data.txt",ios::in);
			a.getline(chrData01,500);
			a.getline(chrData02,500);
			a.getline(chrData03,500);
			a.getline(chrData04,500);
		a.close();
	//----------------------------

	//----------------------------
	//先搜尋是否已經有執行的VLC存在	
		HWND hWnd1;
		hWnd1 = ::FindWindow(NULL, chrData02);
	//----------------------------
		if(hWnd1==NULL)//表示沒有VLC
		{
			//----------------------------
			//使用CreateProcess呼叫VLC	
			//CreateProcess_start
			PROCESS_INFORMATION pi;
			STARTUPINFO si;
			//變數初始化
			memset(&si,0,sizeof(si));
			si.cb=sizeof(si);
			si.wShowWindow=SW_SHOW;
			si.dwFlags=STARTF_USESHOWWINDOW;
			//打開程式
			BOOL fRet=CreateProcess(NULL,
									chrData01,
									NULL,
									NULL,
									FALSE,
									NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,
									NULL,
									NULL,
									&si,
									&pi);
			//CreateProcess_end
			//----------------------------

			//----------------------------
			//等待VLC呼叫完成並移動到指定位置
			HWND hWnd3;
			do
			{
				hWnd3 = ::FindWindow(NULL, chrData02);
				//cout<<"find HWND\n";
			}while(hWnd3==NULL);
			if(hWnd3)
			{
				MoveWindow(hWnd3,atoi(chrData03),atoi(chrData04),0,0,true);
			}
			//----------------------------
		}//if(hWnd1==NULL)
	}//if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))_else

	return nRetCode;
}


