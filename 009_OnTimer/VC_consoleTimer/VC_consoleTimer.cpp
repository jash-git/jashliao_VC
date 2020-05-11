// VC_consoleTimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VC_consoleTimer.h"
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
int gintSize;
int gintindex;
CArray <CString,CString&> m_UrlArray;
CArray <CString,CString&> m_TitleArray;
void Rand_One2N(int intrange,int intstart=1)
{
	srand(time(NULL));
	gintindex=intstart+(rand()%intrange);
}
//===============
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
		//strHello.LoadString(IDS_HELLO);
		//cout << (LPCTSTR)strHello << endl;
		//=========================
		fstream a;
		char fg[700];
		char Num[200];
		char Title[200];
		char Url[200];
		CString StrBuf;
		CString StrCmd;
		a.open("jashliaoblog.csv",ios::in);
		while(!a.eof())
		{
			a.getline(fg,500);
			sscanf (fg ,"%[^','],%[^','],%[^','],",Num,Title,Url);
			StrBuf=Url;
			m_UrlArray.Add(StrBuf);
			StrBuf=Title;
			m_TitleArray.Add(StrBuf);;
		}
		gintSize=m_UrlArray.GetSize();
		Rand_One2N(gintSize,0);
		StrBuf=m_UrlArray.GetAt(gintindex);
		StrCmd="wget -T 15 -t 1 ";
		StrCmd+=StrBuf;
		StrCmd+=" -O wget.html";
		system((LPCTSTR)StrCmd);
		strHello=m_TitleArray.GetAt(gintindex);
		cout << (LPCTSTR)strHello << endl;
		//=========================
		SetTimer(NULL,1,10000,TimeProc);
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
	CString StrBuf;
	CString StrCmd;
	Rand_One2N(gintSize,0);
	StrBuf=m_UrlArray.GetAt(gintindex);
	StrCmd="wget -T 15 -t 1 ";
	StrCmd+=StrBuf;
	StrCmd+=" -O wget.html";
	system((LPCTSTR)StrCmd);
	
	StrBuf=m_TitleArray.GetAt(gintindex);
	cout << (LPCTSTR)StrBuf << endl;
}

