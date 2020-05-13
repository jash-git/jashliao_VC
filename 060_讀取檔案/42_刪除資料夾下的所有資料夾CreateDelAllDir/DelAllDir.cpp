// DelAllDir.cpp: implementation of the CDelAllDir class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CreateDelAllDir.h"
#include "DelAllDir.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDelAllDir::CDelAllDir()
{
	m_Array1.RemoveAll();
}

CDelAllDir::~CDelAllDir()
{

}
void  CDelAllDir::Run()
{
	FILE *pf;
	int i,j;
	CString StrBuf;
	pf=fopen("deldirlog.txt","w");
	j=m_Array1.GetSize();
	for(i=0;i<j;i++)
	{
		StrBuf=m_Array1.GetAt(i);//ㄓ方
		fprintf(pf,"%s\n",StrBuf.GetBuffer(0)); 
		DelFolder(StrBuf);
		RemoveDirectory(StrBuf);
	}
	fclose(pf);
}
void CDelAllDir::DelFolder(CString path)
{
	CFileFind file;
	if(path.Right(1) != "\\")
		path +="\\*.*";
	BOOL bf;
	bf = file.FindFile(path);
	while(bf)
	{
		bf = file.FindNextFile();
		//是文件时直接删除
		if (!file.IsDots() && !file.IsDirectory())
			DeleteFile(file.GetFilePath());
		else if (file.IsDots())
			continue;
		else if (file.IsDirectory())
		{
			path = file.GetFilePath();
			//是目录时,继续递归调用函数删除该目录下的文件
			DelFolder(path);
			//目录为空后删除目录
			RemoveDirectory(path);
		}
	}
}
void CDelAllDir::BrowseDir(CString strDir)
{
	CFileFind ff;
	CString szDir = strDir;
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";	
	szDir += "*.*";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())
		{
			m_Array1.Add(ff.GetFilePath());
			BrowseDir(ff.GetFilePath());
		}
	}
	ff.Close();//关闭
}