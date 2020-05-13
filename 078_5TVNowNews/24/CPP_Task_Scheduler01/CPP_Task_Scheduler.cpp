// CPP_Task_Scheduler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CPP_Task_Scheduler.h"
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
void CALLBACK TimeProc( HWND hwnd, UINT message, UINT idTimer, DWORD dwTime);
int gintcount=0;
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
		cout << "Task Scheduler..." << endl;
		ShellExecute(NULL,"open","RunBat.bat",NULL,NULL,SW_SHOWNORMAL);
		ShellExecute(NULL,"open","GetNowNewsAV.exe",NULL,NULL,SW_SHOWNORMAL); 
		//=========================
		SetTimer(NULL,1,1000,TimeProc);
		MSG   msg;   
		while(GetMessage(&msg,NULL,0,0))   
		{   
			if(msg.message==WM_TIMER)   
			{   
				DispatchMessage(&msg);   
			}
		}
		//=========================
	}

	return nRetCode;
}
void CALLBACK TimeProc( HWND hwnd, UINT message, UINT idTimer, DWORD dwTime)   
{
	gintcount++;
	CTime timeNow=CTime::GetCurrentTime();
	CString StrTime;
	StrTime=timeNow.Format("%Y%m%d_reboot.log");
	CFileFind fFind;
	FILE *pf;
	int hour = timeNow.GetHour();
	int minute = timeNow.GetMinute();
	int Second = timeNow.GetSecond();

	if((gintcount%300)==0)
		ShellExecute(NULL,"open","RunBat.bat",NULL,NULL,SW_SHOWNORMAL); 
	if((gintcount%600)==0)
	{
		ShellExecute(NULL,"open","GetNowNewsAV.exe",NULL,NULL,SW_SHOWNORMAL); 
		gintcount=1;
	}
	if( (hour==4) && (minute==0))
	{
		if( !fFind.FindFile(StrTime) )
		{
			pf=fopen(StrTime.GetBuffer(0),"a");
			fprintf(pf,"time=%d:%d:%d",hour,minute,Second);
			fclose(pf);
			system("shutdown -r -f -t 0");
		}
	}

}

