// GetFileTime.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "GetFileTime.h"

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
		CString fileName;  //要找的檔案名稱(自訂)
		fileName="C:\\mainvideo.wmv";
		WIN32_FIND_DATA FindFileData; //windows 檔案資訊格式
		SYSTEMTIME avd;               //windows system time 格式 (用來接收轉換過後的FileTime)
		FindFirstFile(fileName,&FindFileData);   //把檔案資訊讀到 FindFileData 裡
		cout <<"C:\\mainvideo.wmv"<<endl;
		FileTimeToSystemTime( &FindFileData.ftCreationTime, &avd );  //把 FileTime格式轉成SystemTime格式(這裡只取建立日期日期)
		cout <<"建立日期:"<<avd.wYear<<"-"<<avd.wMonth<<"-"<<avd.wDay<<endl;
		FileTimeToSystemTime( &FindFileData.ftLastAccessTime, &avd );  //把 FileTime格式轉成SystemTime格式(這裡只取最後存取日期)
		cout <<"最後存取日期:"<<avd.wYear<<"-"<<avd.wMonth<<"-"<<avd.wDay<<endl;
		FileTimeToSystemTime( &FindFileData.ftLastWriteTime, &avd );  //把 FileTime格式轉成SystemTime格式(這裡只取最後修改日期)
		cout <<"最後修改日期:"<<avd.wYear<<"-"<<avd.wMonth<<"-"<<avd.wDay<<endl;
	}

	return nRetCode;
}
