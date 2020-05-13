// CallWebService.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "CallWebService.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace net_tw_airnetnoc;//Step 1

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
		/*
		//帶參數的主函數VS2008寫法
		FILE *pf;
		CString Str01,Str02;
		Str01=argv[1];
		Str02=argv[2];
		const size_t strsize01=(Str01.GetLength()+1)*2;
		const size_t strsize02=(Str02.GetLength()+1)*2;
		char * pstr01= new char[strsize01];
		char * pstr02= new char[strsize02];
		size_t sz01=0;
		size_t sz02=0;
		wcstombs_s(&sz01,pstr01,strsize01,Str01,_TRUNCATE);
		wcstombs_s(&sz02,pstr02,strsize02,Str02,_TRUNCATE);
		pf=fopen("Get a Value.txt","w");
		fprintf(pf,"%s,%s",pstr01,pstr02);
		fclose(pf);
		*/
		CoInitialize(NULL);
		BOOL bnlFileOpen;
		noc_Service noc_S;
		//char pstr01[200];
		char pstr02[200];
		CString Str01;
		CString Str02;
		int intstate=0;
		int intcount=0;
		int intServiceID=0;
		int intPlayTime=0;
		int intPlayState=0;
		CString StrName;
		CString StrMMS;
		CString StrBuf;
		String ^netStrName;
		String ^netStrMMS;
		String ^netStrBuf;
		CStdioFile file;
		bnlFileOpen=file.Open(_T("C:\\CallWebServiceData.txt"),CFile::modeRead);
		if(bnlFileOpen)
		{
			size_t sz02=0;
			file.ReadString(Str01);
			if(Str01=="1")//更新
			{
				intstate=1;
				intcount=0;
			}
			if(Str01=="2")//新增
			{
				intstate=2;
				intcount=0;
			}
			if(Str01=="3")//刪除
			{
				intstate=3;
				intcount=0;
			}
			if(Str01=="4")//Enable
			{
				intstate=4;
				intcount=0;
			}
			while(file.ReadString(Str02))
			{
				intcount++;
				const size_t strsize02=(Str02.GetLength()+1)*2;
				wcstombs_s(&sz02,pstr02,strsize02,Str02,_TRUNCATE);
				Str02=pstr02;
				if(intstate==1)//更新
				{
					switch(intcount)
					{
					case 1:
						intServiceID=atoi(pstr02);
						break;
					case 2:
						intPlayTime=atoi(pstr02);
						break;
					case 3:
						intPlayState=atoi(pstr02);
						break;
					case 4:
						StrBuf=Str02;
					};
				}
				if(intstate==2)//新增
				{
					switch(intcount)
					{
					case 1:
						StrName=Str02;
						break;
					case 2:
						StrMMS=Str02;
						break;
					};
				}
				if(intstate==3)//刪除
				{
					switch(intcount)
					{
					case 1:
						intServiceID=atoi(pstr02);
						break;
					};
				}
				if(intstate==4)//Enable
				{
					switch(intcount)
					{
					case 1:
						intServiceID=atoi(pstr02);
						break;
					};
				}
			}
			file.Close();
			::DeleteFile(_T("C:\\CallWebServiceData.txt"));
			switch(intstate)
			{
			case 1://更新
				netStrBuf= gcnew String (StrBuf);
				try
				{
					noc_S.SetServiceStatusByID(intServiceID,intPlayState,intPlayTime,netStrBuf);
				}
				catch(...)
				{
					printf("Get error\n");
				}
				break;
			case 2://新增
				netStrName= gcnew String (StrName);
				netStrMMS= gcnew String (StrMMS);
				try
				{
					noc_S.AddGlobalChannel(netStrName,netStrMMS,0);
				}
				catch(...)
				{
					printf("Get error\n");
				}
				break;
			case 3://刪除
				try
				{
					noc_S.DisableGlobalChannel(intServiceID);
				}
				catch(...)
				{
					printf("Get error\n");
				}
				break;
			case 4://Enable
				try
				{
					noc_S.EnableGlobalChannel(intServiceID);
				}
				catch(...)
				{
					printf("Get error\n");
				}
				break;
			}
			CoUninitialize();
		}
	}
	return nRetCode;
}
