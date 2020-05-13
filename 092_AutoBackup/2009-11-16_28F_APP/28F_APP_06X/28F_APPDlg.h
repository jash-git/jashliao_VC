// 28F_APPDlg.h : header file
//

#if !defined(AFX_28F_APPDLG_H__FEFE35CC_4995_4B7B_8988_3687F267B68B__INCLUDED_)
#define AFX_28F_APPDLG_H__FEFE35CC_4995_4B7B_8988_3687F267B68B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy28F_APPDlg dialog

class CMy28F_APPDlg : public CDialog
{
// Construction
public:
	CMy28F_APPDlg(CWnd* pParent = NULL);	// standard constructor
	FILE *pf;
	bool m_blncheck;
	CString m_StrSaveFile;
	CString m_StrDataFile;
	CString m_StrSearchA,m_StrSearchB;
	void BrowseDir(CString strDir);
	void BrowseFile(CString strDir,CString strfile,bool blnchecktype=true);
// Dialog Data
	//{{AFX_DATA(CMy28F_APPDlg)
	enum { IDD = IDD_MY28F_APP_DIALOG };
	CString	m_FileName;
	CString	m_SavePath;
	CString	m_FilePath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy28F_APPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy28F_APPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowDir();
	afx_msg void OnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_28F_APPDLG_H__FEFE35CC_4995_4B7B_8988_3687F267B68B__INCLUDED_)
