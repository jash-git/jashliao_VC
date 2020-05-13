// ANSI2Unicode_File.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "ANSI2Unicode_File.h"

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
		CStdioFile fileANSI;
		CFile fileUnicode;
		CFile file;
		WORD wSignature = 0xFEFF;
		int intLen;
		char pstrANSI[500];
		CString StrANSI;
		WCHAR pszUnicodeAll[500];//OK->CString長度=陣列長度
		WCHAR pszUnicodeBuf[500]={NULL};
		fileUnicode.Open(_T("123Unicode.txt"), CFile::modeCreate|CFile::modeWrite);
		file.Open(_T("test.txt"), CFile::modeCreate|CFile::modeWrite);
		fileUnicode.Write(&wSignature, 2);
		fileANSI.Open(_T("123.txt"),CFile::modeRead);
		while(fileANSI.ReadString(StrANSI))
		{
			StrANSI+="\r\n";
			////////////////////////////////////////////////////
			//Unicode程式讀ANSI檔案
			const size_t strsize02=(StrANSI.GetLength()+1)*2;
			size_t sz02=0;
			wcstombs_s(&sz02,pstrANSI,strsize02,StrANSI,_TRUNCATE);
			StrANSI=pstrANSI;
			intLen=StrANSI.GetLength();
			/////////////////////////////////////////////////////
			//ANSI字串轉Unicode字串
			wcsncpy(pszUnicodeAll,pszUnicodeBuf,500);
			MultiByteToWideChar(CP_ACP, 0,pstrANSI,-1,pszUnicodeAll,sz02);
			fileUnicode.Write(pszUnicodeAll, lstrlenW(pszUnicodeAll) * sizeof(WCHAR));
			/////////////////////////////////////////////////////
			//Unicode程式寫ANSI檔案
			file.Write(pstrANSI,sz02);
		}
		fileUnicode.Close();
		fileANSI.Close();
		file.Close();
	}

	return nRetCode;
}
