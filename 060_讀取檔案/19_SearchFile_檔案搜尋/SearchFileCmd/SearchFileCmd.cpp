// SearchFileCmd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SearchFileCmd.h"
#include <afxtempl.h>//CArray Step_01 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
CArray <CString,CString&> m_ArrayStrFileName;
void SearchFile(CString strDir,CString strFile);
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
		CString StrPath,StrName;
		CString StrBuffer;
		FILE *pf;
		int i,j;
		if(argc>2)
		{
			StrPath=argv[1];
			StrName=argv[2];
			m_ArrayStrFileName.RemoveAll();
			cout << "搜尋路徑=\t"<<(LPCTSTR)StrPath << endl;
			cout << "搜尋檔名=\t"<<(LPCTSTR)StrName << endl;
			SearchFile(StrPath,StrName);
			j=m_ArrayStrFileName.GetSize();
			StrBuffer=StrName+".smil";
			pf=fopen((LPCTSTR)StrBuffer,"a");
			for(i=0;i<j;i++)
			{
				StrBuffer=m_ArrayStrFileName.GetAt(i);
				fprintf(pf,"%s\n",(LPCTSTR)StrBuffer);
			}
			fclose(pf);
		}
		else
		{
			StrPath=StrName="參數不足";
			cout << (LPCTSTR)StrPath << endl;
		}
	}

	return nRetCode;
}
void SearchFile(CString strDir,CString strFile)
{
	CFileFind ff;
	CString szDir = strDir;

	strFile.MakeLower();
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		CString StrFileName=ff.GetFileName();
		StrFileName.MakeLower();
		int intf=StrFileName.Find(strFile.GetBuffer(0));
		if(intf>=0)
		{
			m_ArrayStrFileName.Add(StrFileName);
		}
		if(ff.IsDirectory() && !ff.IsDots())
		{

			SearchFile(ff.GetFilePath(),strFile);
		}
	}
	ff.Close();

}

