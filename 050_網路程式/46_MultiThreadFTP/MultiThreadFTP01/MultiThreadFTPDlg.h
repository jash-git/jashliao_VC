// MultiThreadFTPDlg.h : header file
//

#if !defined(AFX_MULTITHREADFTPDLG_H__D93CA6B7_699B_423B_8521_B954CC21E7A5__INCLUDED_)
#define AFX_MULTITHREADFTPDLG_H__D93CA6B7_699B_423B_8521_B954CC21E7A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadFTPDlg dialog

class CMultiThreadFTPDlg : public CDialog
{
// Construction
public:
	CMultiThreadFTPDlg(CWnd* pParent = NULL);	// standard constructor
	int m_intStep;
	int m_intSum;
	int m_intCount;
	int m_intThreadCount;
	int m_intCheckThread;
	int m_intThreadSum;
	CString StrShowData[5];
	CArray <CString,CString&> m_ArrayListIP;//CArray Step_02
	void ReadListFile();//(Data to CArray)
	int GetIPData();//一次固訂取出5筆資料
	void ShowIPData();//將資料顯示在介面上
	void WaitThread();//等待執行緒
	static UINT Thread00(LPVOID lpram);//執行緒
	static UINT Thread01(LPVOID lpram);//執行緒
	static UINT Thread02(LPVOID lpram);//執行緒
	static UINT Thread03(LPVOID lpram);//執行緒
	static UINT Thread04(LPVOID lpram);//執行緒
	void Thread00Fun();//執行緒主體，FTP清單、下載，建立資料夾
	void Thread01Fun();//執行緒主體，FTP清單、下載，建立資料夾
	void Thread02Fun();//執行緒主體，FTP清單、下載，建立資料夾
	void Thread03Fun();//執行緒主體，FTP清單、下載，建立資料夾
	void Thread04Fun();//執行緒主體，FTP清單、下載，建立資料夾
// Dialog Data
	//{{AFX_DATA(CMultiThreadFTPDlg)
	enum { IDD = IDD_MULTITHREADFTP_DIALOG };
	CString	m_StrIP00;
	CString	m_StrIP01;
	CString	m_StrIP02;
	CString	m_StrIP03;
	CString	m_StrIP04;
	CString	m_StrIPCount;
	CString	m_StrIPSum;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThreadFTPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThreadFTPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREADFTPDLG_H__D93CA6B7_699B_423B_8521_B954CC21E7A5__INCLUDED_)
