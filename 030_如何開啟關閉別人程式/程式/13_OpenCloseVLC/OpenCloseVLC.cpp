// OpenCloseVLC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OpenCloseVLC.h"
#include <afxtempl.h>//CArray Step_01 
#include <fstream>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
using namespace std;
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
		/*
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;
		*/
		CString gStrTitleArrBuf;
		CString gStrBatArrBuf;
		CArray <CString,CString&> m_BatArray;
		CArray <CString,CString&> m_TitleArray;
		m_BatArray.RemoveAll();
		m_TitleArray.RemoveAll();
		fstream a;
		char fg[500];
		char Title[100];
		char Bat[200];
		a.open("urlList.txt",ios::in);
		while(!a.eof())
		{
			a.getline(fg,500);
			sscanf (fg ,"%[^','],%[^','],",Title,Bat);
			gStrTitleArrBuf=Title;
			m_TitleArray.Add(gStrTitleArrBuf);
			gStrBatArrBuf=Bat;
			m_BatArray.Add(gStrBatArrBuf);
		}
		////////////////////////////////////////
		CTime t1=CTime::GetCurrentTime();
		CString StrFileName,StrBuf;
		FILE *pfLogFile;
		HWND hWnd01,hWnd02;
		StrFileName=t1.Format("%Y%m%d%H%M%_logs.csv");
		pfLogFile=fopen(StrFileName.GetBuffer(0),"w"); 
		int i,j;
		j=m_TitleArray.GetSize();
		for(i=0;i<j;i++)
		{
			StrBuf=m_TitleArray.GetAt(i);//來源
			hWnd01 = FindWindow(NULL,StrBuf);
			if(hWnd01 == 0)
			{
				//找不到指定程式
				//表示已斷線
				hWnd02 = FindWindow(NULL,"VLC媒體播放程式");
				if(hWnd02 != 0)
				{
					PostMessage(hWnd02, WM_CLOSE, 0, 0);
				}
				StrBuf=m_BatArray.GetAt(i);//來源
				ShellExecute(NULL,"open",StrBuf,NULL,NULL,SW_SHOWNORMAL); 
				fprintf(pfLogFile,"%s,%s\n",StrBuf.GetBuffer(0),"reload");
				cout << (LPCTSTR)StrBuf <<"reload" << endl;
			}
			else
			{
				StrBuf=m_TitleArray.GetAt(i);//來源
				fprintf(pfLogFile,"%s,%s\n",StrBuf.GetBuffer(0),"is OK");
				cout << (LPCTSTR)StrBuf <<"is OK" << endl;
			}
		}
		fclose(pfLogFile);
	}

	return nRetCode;
}


