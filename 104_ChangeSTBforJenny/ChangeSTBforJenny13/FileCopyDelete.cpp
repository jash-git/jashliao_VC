// FileCopyDelete.cpp: implementation of the CFileCopyDelete class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FileCopyDelete.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileCopyDelete::CFileCopyDelete()
{
	m_ArraySource.RemoveAll();//Step 2:CArray//存放來源檔案資料
	m_ArrayDestination.RemoveAll();//Step 2:CArray//存放目的檔案資料
	m_ArrayOutcome.RemoveAll();//Step 2:CArray//存放執行結果
}
CFileCopyDelete::CFileCopyDelete(CString S1,CString D1)
{
	m_StrSourcePath=S1;
	m_StrDestinationPath=D1;
	m_ArraySource.RemoveAll();//Step 2:CArray//存放來源檔案資料
	m_ArrayDestination.RemoveAll();//Step 2:CArray//存放目的檔案資料
	m_ArrayOutcome.RemoveAll();//Step 2:CArray//存放執行結果
}
CFileCopyDelete::~CFileCopyDelete()
{

}
void CFileCopyDelete::CopyAllFile(CString S1,CString D1)
{
	m_StrSourcePath=S1;
	m_StrDestinationPath=D1;
	FindSourceFile();
	//
	CString StrNetFileName,StrPlayDataFileName;
	CString StrFileName;
	CString StrOutcome;
	int i,j;
	j=m_ArraySource.GetSize(); 
	for(i=0;i<j;i++)
	{
		StrFileName=m_ArraySource.GetAt(i); 
		StrNetFileName=m_StrSourcePath+StrFileName;//來源
		StrPlayDataFileName=m_StrDestinationPath+StrFileName;//目的
		if(CopyFile(StrNetFileName.GetBuffer(0),StrPlayDataFileName.GetBuffer(0),false))
		{
			StrOutcome.Format("Copy %s to %s ->OK",StrNetFileName,StrPlayDataFileName);
		}
		else
		{
			StrOutcome.Format("Copy %s to %s ->Not OK",StrNetFileName,StrPlayDataFileName);
		}
		/*
		m_intNowCount=i;
		m_StrNowFilePath=StrNetFileName;
		Sleep(1000);
		*/
		m_ArrayOutcome.Add(StrOutcome);
	}
}
void CFileCopyDelete::CopyAllFile()
{
	CString StrNetFileName,StrPlayDataFileName;
	CString StrFileName;
	CString StrOutcome;
	int i,j;
	j=m_ArraySource.GetSize(); 
	for(i=0;i<j;i++)
	{
		StrFileName=m_ArraySource.GetAt(i); 
		StrNetFileName=m_StrSourcePath+StrFileName;//來源
		StrPlayDataFileName=m_StrDestinationPath+StrFileName;//目的
		if(CopyFile(StrNetFileName.GetBuffer(0),StrPlayDataFileName.GetBuffer(0),false))
		{
			StrOutcome.Format("Copy %s to %s ->OK",StrNetFileName,StrPlayDataFileName);
		}
		else
		{
			StrOutcome.Format("Copy %s to %s ->Not OK",StrNetFileName,StrPlayDataFileName);
		}
		/*
		m_intNowCount=i;
		m_StrNowFilePath=StrNetFileName;
		Sleep(1000);
		*/
		m_ArrayOutcome.Add(StrOutcome);
	}
}
void CFileCopyDelete::DeleteAllFile(CString S1,CString D1,int index)
{
	m_StrSourcePath=S1;
	m_StrDestinationPath=D1;
	FindDestinationFile(index);
	CString StrNetFileName;
	CString StrFileName;
	CString StrOutcome;
	int i,j;
	j=m_ArrayDestination.GetSize(); 
	for(i=0;i<j;i++)
	{
		StrFileName=m_ArrayDestination.GetAt(i); 
		if(DeleteFile(StrFileName.GetBuffer(0)))
		{
			StrOutcome.Format("Delete %s ->OK",StrFileName);
		}
		else
		{
			StrOutcome.Format("Delete %s ->Not OK",StrFileName);
		}
		/*
		m_intNowCount=i;
		m_StrNowFilePath=StrFileName;
		Sleep(1000);
		*/
		m_ArrayOutcome.Add(StrOutcome);
	}
}
void CFileCopyDelete::DeleteAllFile()
{
	CString StrNetFileName;
	CString StrFileName;
	CString StrOutcome;
	int i,j;
	j=m_ArrayDestination.GetSize(); 
	for(i=0;i<j;i++)
	{
		StrFileName=m_ArrayDestination.GetAt(i); 
		if(DeleteFile(StrFileName.GetBuffer(0)))
		{
			StrOutcome.Format("Delete %s ->OK",StrFileName);
		}
		else
		{
			StrOutcome.Format("Delete %s ->Not OK",StrFileName);
		}
		/*
		m_intNowCount=i;
		m_StrNowFilePath=StrFileName;
		Sleep(1000);
		*/
		m_ArrayOutcome.Add(StrOutcome);
	}
}
void CFileCopyDelete::FindSourceFile()
{
	m_ArraySource.RemoveAll(); 
	BrowseDir(m_StrSourcePath,1);//來源
}
void CFileCopyDelete::FindDestinationFile(int index)
{
	m_ArrayDestination.RemoveAll();
	BrowseDir(m_StrDestinationPath,2,index);//目的地
}
void CFileCopyDelete::FindSourceFile(CString StrPath)
{
	m_ArraySource.RemoveAll(); 
	m_StrSourcePath=StrPath;
	BrowseDir(m_StrSourcePath,1);//來源
}
void CFileCopyDelete::FindDestinationFile(CString StrPath)
{
	m_ArrayDestination.RemoveAll(); 
	m_StrDestinationPath=StrPath;
	BrowseDir(m_StrDestinationPath,2);//目的地
}
void CFileCopyDelete::BrowseDir(CString strDir,int intindex,int intchrck)//Step 2:列出檔案清單
{
	CFileFind ff;
	CString szDir = strDir;
	int intcontrol=0;
	intcontrol=intindex;
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())
		{
			if(intindex==1)
			{
				BrowseDir(ff.GetFilePath(),intcontrol);
			}
			if(intindex==2 && intchrck==1)
			{
				BrowseDir(ff.GetFilePath(),intcontrol,1);
			}
		}
		else if(!ff.IsDirectory() && !ff.IsDots())
		{
			//m_Array.Add(ff.GetFilePath());
			switch(intindex)
			{
				case 1://來源
					m_ArraySource.Add(ff.GetFileName());
					break;
				case 2://目的地
					m_ArrayDestination.Add(ff.GetFilePath());
					break;
			};
		}
	}
	ff.Close();
}
int CFileCopyDelete::GetCopyFileNumber()
{
	int intnumber;
	FindSourceFile();
	intnumber=m_ArraySource.GetSize();
	return intnumber;
}
int CFileCopyDelete::GetDeleteFileNumber()
{
	int intnumber;
	FindDestinationFile(0);
	intnumber=m_ArrayDestination.GetSize();
	return intnumber;
}
CString CFileCopyDelete::GetCopyTheFileName(int intindex)
{
	CString StrBuf;
	StrBuf=m_ArraySource.GetAt(intindex);
	return StrBuf;
}
CString CFileCopyDelete::GetDeleteTheFileName(int intindex)
{
	CString StrBuf;
	StrBuf=m_ArrayDestination.GetAt(intindex);
	return StrBuf;
}
void CFileCopyDelete::CopyOneFile(int intindex)
{
	CString StrNetFileName,StrPlayDataFileName;
	CString StrFileName;
	CString StrOutcome;
	StrFileName=m_ArraySource.GetAt(intindex); 
	StrNetFileName=m_StrSourcePath+StrFileName;//來源
	StrPlayDataFileName=m_StrDestinationPath+StrFileName;//目的
	if(CopyFile(StrNetFileName.GetBuffer(0),StrPlayDataFileName.GetBuffer(0),false))
	{
		StrOutcome.Format("Copy %s to %s ->OK",StrNetFileName,StrPlayDataFileName);
	}
	else
	{
		StrOutcome.Format("Copy %s to %s ->Not OK",StrNetFileName,StrPlayDataFileName);
	}
	/*
	m_intNowCount=i;
	m_StrNowFilePath=StrNetFileName;
	Sleep(1000);
	*/
	m_ArrayOutcome.Add(StrOutcome);
}
void CFileCopyDelete::DeleteOneFile(int intindex)
{
	CString StrNetFileName;
	CString StrFileName;
	CString StrOutcome;
	StrFileName=m_ArrayDestination.GetAt(intindex); 
	if(DeleteFile(StrFileName.GetBuffer(0)))
	{
		StrOutcome.Format("Delete %s ->OK",StrFileName);
	}
	else
	{
		StrOutcome.Format("Delete %s ->Not OK",StrFileName);
	}
	/*
	m_intNowCount=i;
	m_StrNowFilePath=StrFileName;
	Sleep(1000);
	*/
	m_ArrayOutcome.Add(StrOutcome);
}
void CFileCopyDelete::Output2File(CString StrFileName)
{
	int i,j;
	FILE *pf;
	CString StrBuf;
	pf=fopen(StrFileName.GetBuffer(0),"a");
	j=m_ArrayOutcome.GetSize();
	for(i=0;i<j;i++)
	{
		StrBuf=m_ArrayOutcome.GetAt(i);
		fprintf(pf,"%s\n",StrBuf.GetBuffer(0)); 
	}
	fclose(pf);
}
void CFileCopyDelete::CopyOneFile(CString StrSourceFile,CString StrDestinationFile)
{
	CString StrNetFileName,StrPlayDataFileName;
	CString StrOutcome;
	StrNetFileName=StrSourceFile;//來源
	StrPlayDataFileName=StrDestinationFile;//目的
	if(CopyFile(StrNetFileName.GetBuffer(0),StrPlayDataFileName.GetBuffer(0),false))
	{
		StrOutcome.Format("Copy %s to %s ->OK",StrNetFileName,StrPlayDataFileName);
	}
	else
	{
		StrOutcome.Format("Copy %s to %s ->Not OK",StrNetFileName,StrPlayDataFileName);
	}
	/*
	m_intNowCount=i;
	m_StrNowFilePath=StrNetFileName;
	Sleep(1000);
	*/
	m_ArrayOutcome.Add(StrOutcome);
}
void CFileCopyDelete::DeleteOneFile(CString StrDestinationFile)
{
	CString StrFileName;
	CString StrOutcome;
	StrFileName=StrDestinationFile;
	if(DeleteFile(StrFileName.GetBuffer(0)))
	{
		StrOutcome.Format("Delete %s ->OK",StrFileName);
	}
	else
	{
		StrOutcome.Format("Delete %s ->Not OK",StrFileName);
	}
	/*
	m_intNowCount=i;
	m_StrNowFilePath=StrFileName;
	Sleep(1000);
	*/
	m_ArrayOutcome.Add(StrOutcome);
}
void CFileCopyDelete::GetArrayData(int intindex,CArray <CString,CString&> *ArrayTemp)
{
	int i,j;
	switch(intindex)
	{
		case 1:
			j=m_ArraySource.GetSize();
			for(i=0;i<j;i++)
			{
				ArrayTemp->Add(m_ArraySource.GetAt(i));//Step 2:CArray//存放來源檔案資料
			}
			break;
		case 2:
			j=m_ArrayDestination.GetSize();
			for(i=0;i<j;i++)
			{
				ArrayTemp->Add(m_ArrayDestination.GetAt(i));//Step 2:CArray//存放目的檔案資料
			}
			break;
		case 3:
			j=m_ArrayOutcome.GetSize();
			for(i=0;i<j;i++)
			{
				ArrayTemp->Add(m_ArrayOutcome.GetAt(i));//Step 2:CArray//存放執行結果
			}
			break;
	};
}
void CFileCopyDelete::RecursiveDelete(CString szPath)
{
	CFileFind ff;
	CString path = szPath;
	if(path.Right(1) != "\\")
	{
		path += "\\";
	}
	path += "*.*";
	BOOL res = ff.FindFile(path);
	while(res)
	{
		res = ff.FindNextFile();
		if (!ff.IsDots() && !ff.IsDirectory())
		{
			DeleteFile(ff.GetFilePath());
		}
		else if (ff.IsDots())
		{
			continue;
		}
		else if (ff.IsDirectory())
		{
			path = ff.GetFilePath();
			RecursiveDelete(path);
			RemoveDirectory(path);
		}
	}
	RemoveDirectory(szPath);
}