// VS2008CString.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "VS2008CString.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
/*
<stdlib.h> <math.h> <wchar.h>
	ASCII		UNICODE		TCHAR		VS2005
int	atoi		_wtoi		_tstoi 		_atoi_l 
							_ttoi		_wtoi_l

long	atol	_wtol		_tstoi		_atoi_l  
							_ttoi		_wtoi_l

double	atof	_wtof		_tstof		_atof_l 
							_ttof		_wtof_l 
*/

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
	}
	/* CString 轉換成 LPTSTR */
	//(1)強制轉換
	CString strText( _T("This is a test") );
	LPTSTR lpszText =(LPTSTR)(LPCTSTR)strText;
	::MessageBox(NULL,lpszText, _T("標題"),MB_ICONASTERISK|MB_TASKMODAL|MB_OK);
	//(2)使用lstrcpy()
	lpszText = new TCHAR[strText.GetLength()+1];
	lstrcpy( lpszText, strText );
	::MessageBox(NULL,lpszText, _T("標題"), MB_ICONASTERISK|MB_TASKMODAL|MB_OK);

	CString theString=_T("This is a test");
	theString=_T("100");

	/* CString -> LPTSTR */
	LPTSTR lpsz = new TCHAR[theString.GetLength()+1];
	_tcscpy(lpsz, theString);

	/* LPTSTR ->int */
	int chr2int;
	chr2int=_wtoi(lpsz);//chr2int=_ttoi(lpsz);

	/* LPTSTR ->float */
	float chr2float;
	chr2float=_wtof(lpsz);

	/*int -> CString*/
	CString s;
	int i = 64;
	s.Format(L"%d",i);

	//Unicode下CString轉換為char *
	CString str = _T("123,456,789");
	//注意：以下n和len的值大小不同,n是按字元計算的，len是按位元組計算的
	int n = str.GetLength();
	//獲取寬位元組字元的大小，大小是按位元組計算的
	int len = WideCharToMultiByte(CP_ACP,0,str,str.GetLength(),NULL,0,NULL,NULL);
	//為多位元組字元陣列申請空間，陣列大小為按位元組計算的寬位元組位元組大小
	char * pFileName = new char[len+1];   //以位元組為單位
	//寬位元組編碼轉換成多位元組編碼
	WideCharToMultiByte(CP_ACP,0,str,str.GetLength(),pFileName,len,NULL,NULL);
	pFileName[len] = '\0'; //添加字串結尾，注意不是len+1

	//sscanf
	char Schrd01[500],Schrd02[500],Schrd03[500];
	int ih01,ih02,ih03;
	float fh01,fh02,fh03;

	sscanf (pFileName ,"%[^','],%[^','],%s",Schrd01,Schrd02,Schrd03);
	ih01=atoi(Schrd01);
	ih02=atoi(Schrd02);
	ih03=atoi(Schrd03);
	fh01=atof(Schrd01);
	fh02=atof(Schrd02);
	fh03=atof(Schrd03);

	delete [] pFileName;
	//Unicode下char *轉換為CString
	char *pFileName1 = "D:\\校內項目\\QQ.bmp";
	//計算char *陣列大小，以位元組為單位，一個漢字占兩個位元組
	int charLen = strlen(pFileName1);
	//計算多位元組字元的大小，按字元計算。
	len = MultiByteToWideChar(CP_ACP,0,pFileName1,charLen,NULL,0);
	//為寬位元組字元陣列申請空間，陣列大小為按位元組計算的多位元組字元大小
	TCHAR *buf = new TCHAR[len + 1];
	//多位元組編碼轉換成寬位元組編碼
	MultiByteToWideChar(CP_ACP,0,pFileName1,charLen,buf,len);
	buf[len] = '\0'; //添加字串結尾，注意不是len+1
	CString pWideChar;
	pWideChar.Append(buf);
	delete [] buf;

	return nRetCode;
}
