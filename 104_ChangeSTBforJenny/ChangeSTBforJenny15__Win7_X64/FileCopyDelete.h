// FileCopyDelete.h: interface for the CFileCopyDelete class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILECOPYDELETE_H__6745933E_3B42_4A34_81E8_B4B0DBB776C0__INCLUDED_)
#define AFX_FILECOPYDELETE_H__6745933E_3B42_4A34_81E8_B4B0DBB776C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>//CArray Step_01 
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
	//方法3->執行緒
	UINT CCreateFileCopyDeleteDlg::ThreadFun(LPVOID lpram)//Step 2:執行緒
	{
		//CCreateFileCopyDeleteDlg *u=(CCreateFileCopyDeleteDlg *)AfxGetMainWnd();
		CCreateFileCopyDeleteDlg *u=(CCreateFileCopyDeleteDlg *)lpram;
		CFileCopyDelete *pFCD1;
		CString Str_S,Str_D;
		int k,l;
		u->MessageBox(u->m_v1);
		u->MessageBox(u->m_v2);
		Str_S=u->m_v1;
		Str_D=u->m_v2;
		pFCD1=new CFileCopyDelete(Str_S,Str_D);
		l=pFCD1->GetDeleteFileNumber(); 
		for(k=0;k<l;k++)
		{
			u->SetDlgItemInt(IDC_EDIT3,k);
			u->SetDlgItemText(IDC_EDIT4,pFCD1->GetDeleteTheFileName(k));
			pFCD1->DeleteOneFile(k);
			Sleep(100);
		}
		pFCD1->Output2File("456.txt");
		delete pFCD1;
		u->MessageBox("OK");
		return 0;
	}
	UINT CCreateFileCopyDeleteDlg::ThreadFun1(LPVOID lpram)//Step 2:執行緒
	{
		CCreateFileCopyDeleteDlg *u=(CCreateFileCopyDeleteDlg *)lpram;
		CFileCopyDelete *pFCD1;
		CString Str_S,Str_D;
		int k,l;
		u->MessageBox(u->m_v1);
		u->MessageBox(u->m_v2);
		Str_S=u->m_v1;
		Str_D=u->m_v2;
		pFCD1=new CFileCopyDelete(Str_S,Str_D);
		l=pFCD1->GetCopyFileNumber(); 
		for(k=0;k<l;k++)
		{
			u->SetDlgItemInt(IDC_EDIT3,k);
			u->SetDlgItemText(IDC_EDIT4,pFCD1->GetCopyTheFileName(k));
			pFCD1->CopyOneFile(k);
			Sleep(100);
		}
		pFCD1->Output2File("123.txt");
		delete pFCD1;
		u->MessageBox("OK");
		return 0;
	}
	void CCreateFileCopyDeleteDlg::OnButton7() 
	{
		// TODO: Add your control notification handler code here
		UpdateData(true);
		CWinThread *pr=AfxBeginThread(ThreadFun1,this,0,0,0,NULL);
	}

	void CCreateFileCopyDeleteDlg::OnButton8() 
	{
		// TODO: Add your control notification handler code here
		UpdateData(true);
		CWinThread *pr=AfxBeginThread(ThreadFun,this,0,0,0,NULL);	
	}
	*/
	CFileCopyDelete();
	CFileCopyDelete(CString S1,CString D1);
	void FindSourceFile(CString StrPath);
	void FindDestinationFile(CString StrPath);
	void FindSourceFile();
	void FindDestinationFile(int index);
	void CopyAllFile(CString S1,CString D1);
	void CopyAllFile();
	void DeleteAllFile(CString S1,CString D1,int index=0);
	void DeleteAllFile();
	void Output2File(CString StrFileName);
	int GetCopyFileNumber();
	int GetDeleteFileNumber();
	CString GetCopyTheFileName(int intindex);
	CString GetDeleteTheFileName(int intindex);
	void CopyOneFile(int intindex);
	void DeleteOneFile(int intindex);
	void CopyOneFile(CString StrSourceFile,CString StrDestinationFile);
	void DeleteOneFile(CString StrDestinationFile);
	void GetArrayData(int intindex,CArray <CString,CString&> *ArrayTemp);
	void BrowseDir(CString strDir,int intindex,int intchrck=0);//Step 2:列出檔案清單
	void RecursiveDelete(CString szPath);
	virtual ~CFileCopyDelete();
	//int m_intNowCount;
	//CString m_StrNowFilePath;
protected:
	CArray <CString,CString&> m_ArraySource;//Step 2:CArray//存放來源檔案資料
	CArray <CString,CString&> m_ArrayDestination;//Step 2:CArray//存放目的檔案資料
	CArray <CString,CString&> m_ArrayOutcome;//Step 2:CArray//存放執行結果
	CString m_StrSourcePath,m_StrDestinationPath;
};

#endif // !defined(AFX_FILECOPYDELETE_H__6745933E_3B42_4A34_81E8_B4B0DBB776C0__INCLUDED_)
