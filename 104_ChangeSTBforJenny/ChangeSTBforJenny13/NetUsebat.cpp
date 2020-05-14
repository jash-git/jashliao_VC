// NetUsebat.cpp: implementation of the CNetUsebat class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NetUsebat.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNetUsebat::CNetUsebat()
{
	StrCreateBuf="";
	StrDeleteBuf="";//Bat檔名
	StrCreateAns="";
	StrDeleteAns="";//結果檔名
}
CNetUsebat::CNetUsebat(CString StrName,CString StrPWS,CString StrData,int intCount)
{
	StrCreateBuf="";
	StrDeleteBuf="";//Bat檔名
	StrCreateAns="";
	StrDeleteAns="";//結果檔名
	Createbat(StrName,StrPWS,StrData,intCount);
}
void CNetUsebat::Createbat(CString StrName,CString StrPWS,CString StrData,int intCount)
{
	StrCreateBuf="";
	StrDeleteBuf="";//Bat檔名
	StrCreateAns="";
	StrDeleteAns="";//結果檔名
	FILE *pfcreate,*pfdelete;
	CString StrDataBuf1,StrDataBuf2;
	StrCreateBuf.Format("createbat_%d.bat",intCount);
	StrDeleteBuf.Format("deletebat_%d.bat",intCount);
	//**
	pfcreate=fopen(StrCreateBuf.GetBuffer(0),"w");
	pfdelete=fopen(StrDeleteBuf.GetBuffer(0),"w");
	StrDataBuf1="net use ";
	StrDataBuf2.Format(" \"%s\" /user:%s >Create_Ans%d.txt",StrPWS.GetBuffer(0),StrName.GetBuffer(0),intCount);
	StrCreateAns.Format("Create_Ans%d.txt",intCount); 
	StrDataBuf1+=StrData;
	StrDataBuf1+=StrDataBuf2;
	fprintf(pfcreate,"%s",StrDataBuf1.GetBuffer(0));
	//**
	StrDataBuf1="net use ";
	StrDataBuf2.Format(" >Delete_Ans%d.txt",intCount);
	StrDeleteAns.Format("Delete_Ans%d.txt",intCount);
	StrDataBuf1+=StrData;
	StrDataBuf1+=" /delete";
	StrDataBuf1+=StrDataBuf2;
	fprintf(pfdelete,"%s",StrDataBuf1.GetBuffer(0));
	//**
	fclose(pfcreate);
	fclose(pfdelete);
}
bool CNetUsebat::CreateShareDir()
{
	bool blncheckfile;
	char chrbuf[500];
	CString StrBuf;
	blncheckfile=false;
	//ShellExecute(NULL,"open",StrCreateBuf,NULL,NULL,SW_SHOWNORMAL);
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = StrCreateBuf;		
	ShExecInfo.lpParameters = "";	
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_MINIMIZE;
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
	FILE *pf;
	do
	{
		//Sleep(5000);
		pf=fopen(StrCreateAns.GetBuffer(0),"r");
		if(pf==NULL)
		{
			blncheckfile=false;
		}
		else
		{
			blncheckfile=true;
		}
	}while(blncheckfile==false);
	blncheckfile=false;
	while(fscanf(pf,"%s",chrbuf)!=EOF)
	{
		StrBuf=chrbuf;
		if(StrBuf=="命令執行成功。")
		{
			blncheckfile=true;
			break;
		}
		else
		{
			blncheckfile=false;
		}
	}
	fclose(pf);
	DeleteFile(StrCreateAns);
	DeleteFile(StrCreateBuf);
	DeleteFile(StrDeleteBuf);
	DeleteFile(StrCreateAns);
	DeleteFile(StrDeleteAns);
	return blncheckfile;
}
void CNetUsebat::DeleteShareDir()
{
	ShellExecute(NULL,"open",StrDeleteBuf,NULL,NULL,SW_SHOWNORMAL);
}
CNetUsebat::~CNetUsebat()
{
}
