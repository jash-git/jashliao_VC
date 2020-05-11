// JashtestFTPDlg.h : header file
//

#if !defined(AFX_JASHTESTFTPDLG_H__B3FA6E26_6449_4E0E_A45E_F43772340566__INCLUDED_)
#define AFX_JASHTESTFTPDLG_H__B3FA6E26_6449_4E0E_A45E_F43772340566__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJashtestFTPDlg dialog

class CJashtestFTPDlg : public CDialog
{
// Construction
public:
	CJashtestFTPDlg(CWnd* pParent = NULL);	// standard constructor
	CInternetSession *m_pInetSession; //FTP_2
	CFtpConnection *m_pFtpConnection; 
	void GetSettingData();
	CString m_StrServerName,m_StrUserName,m_StrPassWord;
// Dialog Data
	//{{AFX_DATA(CJashtestFTPDlg)
	enum { IDD = IDD_JASHTESTFTP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJashtestFTPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CJashtestFTPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JASHTESTFTPDLG_H__B3FA6E26_6449_4E0E_A45E_F43772340566__INCLUDED_)
