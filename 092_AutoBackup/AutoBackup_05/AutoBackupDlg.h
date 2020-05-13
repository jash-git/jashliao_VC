// AutoBackupDlg.h : header file
//

#if !defined(AFX_AUTOBACKUPDLG_H__A2B95326_B98F_4BA1_B34A_529B41F0BC4E__INCLUDED_)
#define AFX_AUTOBACKUPDLG_H__A2B95326_B98F_4BA1_B34A_529B41F0BC4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAutoBackupDlg dialog

class CAutoBackupDlg : public CDialog
{
// Construction
public:
	CAutoBackupDlg(CWnd* pParent = NULL);	// standard constructor
	void BrowseDir(CString strDir);
	void BrowseFile(CString strDir,CString strfile,bool blnchecktype=true);
// Dialog Data
	//{{AFX_DATA(CAutoBackupDlg)
	enum { IDD = IDD_AUTOBACKUP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoBackupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
protected:
	CString m_StrRoot;
	FILE *pf;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAutoBackupDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFindfolders();
	afx_msg void OnFindWord();
	afx_msg void OnFindExcel();
	afx_msg void OnFindPowerPoint1();
	afx_msg void OnFindPowerPoint2();
	afx_msg void OnFindWinZip();
	afx_msg void OnFindWinRAR();
	afx_msg void OnFindAccess();
	afx_msg void OnFindMXF();
	afx_msg void OnFindName();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOBACKUPDLG_H__A2B95326_B98F_4BA1_B34A_529B41F0BC4E__INCLUDED_)
