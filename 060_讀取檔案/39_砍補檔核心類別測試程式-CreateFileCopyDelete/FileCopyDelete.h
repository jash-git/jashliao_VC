// FileCopyDelete.h: interface for the CFileCopyDelete class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILECOPYDELETE_H__6745933E_3B42_4A34_81E8_B4B0DBB776C0__INCLUDED_)
#define AFX_FILECOPYDELETE_H__6745933E_3B42_4A34_81E8_B4B0DBB776C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFileCopyDelete  
{
public:
	/*
	使用組合
	//方法1
	CFileCopyDelete FCD(m_v1,m_v2);
	FCD.FindDestinationFile();/	FCD.FindSourceFile(); 
	FCD.DeleteAllFile();/ FCD.CopyAllFile();
	FCD.Output2File("456.txt");
	//方法2
	pFCD=new CFileCopyDelete();
	pFCD->CopyAllFile(m_v1,m_v2);/pFCD->DeleteAllFile(m_v1,m_v2);
	pFCD->Output2File("123.txt");
	delete pFCD;
	UpdateData(false);
	*/
	CFileCopyDelete();
	CFileCopyDelete(CString S1,CString D1);
	void FindSourceFile(CString StrPath);
	void FindDestinationFile(CString StrPath);
	void FindSourceFile();
	void FindDestinationFile();
	void CopyAllFile(CString S1,CString D1);
	void CopyAllFile();
	void DeleteAllFile(CString S1,CString D1);
	void DeleteAllFile();
	void Output2File(CString StrFileName);
	int GetCopyFileNumber();
	int GetDeleteFileNumber();
	CString GetCopyTheFileName(int intindex);
	CString GetDeleteTheFileName(int intindex);
	void CopyOneFile(int intindex);
	void DeleteOneFile(int intindex);
	virtual ~CFileCopyDelete();
	//int m_intNowCount;
	//CString m_StrNowFilePath;
protected:
	void BrowseDir(CString strDir,int intindex);//Step 2:列出檔案清單
	CArray <CString,CString&> m_ArraySource;//Step 2:CArray//存放來源檔案資料
	CArray <CString,CString&> m_ArrayDestination;//Step 2:CArray//存放目的檔案資料
	CArray <CString,CString&> m_ArrayOutcome;//Step 2:CArray//存放執行結果
	CString m_StrSourcePath,m_StrDestinationPath;
};

#endif // !defined(AFX_FILECOPYDELETE_H__6745933E_3B42_4A34_81E8_B4B0DBB776C0__INCLUDED_)
