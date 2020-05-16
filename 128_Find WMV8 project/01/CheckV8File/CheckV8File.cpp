// CheckV8File.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CheckV8File.h"
#include<stdio.h>
#include<fstream>
#include <stdlib.h>
#include <string.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
TCHAR gstrCurDrt[500];
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

		int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
		if( gstrCurDrt[nLen]!='\\' )
		{
			gstrCurDrt[nLen++] = '\\';
			gstrCurDrt[nLen] = '\0';
		}
		CString StrFileList;
		CString StrFile;
		fstream a;
		FILE *pfV8log;
		char fa[700];
		char fg[700];
		char check[700]="Windows Media Video 8";
		char *loc;
		bool blnfind=false;
		int intcount=0;
		StrFileList= gstrCurDrt;
		StrFileList+="SearchFile2SQLite.txt";
		a.open(StrFileList.GetBuffer(0),ios::in);
		while(!a.eof())
		{
			a.getline(fa,700);
			StrFile=fa;
			if(StrFile=="")
				break;
			StrFile=StrFile.Mid((StrFile.ReverseFind('\\')+1),(StrFile.GetLength()-StrFile.ReverseFind('\\')));
			StrFile="TXT_data\\"+StrFile;
			StrFile+=".txt";
			StrFile= gstrCurDrt+StrFile;
			fstream b;
			b.open(StrFile.GetBuffer(0),ios::in);
			while(!b.eof())
			{
				b.getline(fg,700);
				loc = strstr(fg, check);
				if(loc != NULL)
				{
					pfV8log=fopen("CheckV8log.txt","a");
					fprintf(pfV8log,"%s\n",fa);
					fclose(pfV8log);
					cout <<"find a file= "<< fa << endl;
					pfV8log=NULL;
					blnfind=true;
					break;
				}
			}
			b.close();
		}
		a.close();

	}

	return nRetCode;
}


