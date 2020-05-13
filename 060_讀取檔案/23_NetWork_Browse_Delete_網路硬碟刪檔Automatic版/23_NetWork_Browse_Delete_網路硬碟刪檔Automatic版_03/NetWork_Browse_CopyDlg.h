// NetWork_Browse_CopyDlg.h : header file
//

#if !defined(AFX_NETWORK_BROWSE_COPYDLG_H__2487B07B_978D_4A9E_957C_8E78D6EEAC4D__INCLUDED_)
#define AFX_NETWORK_BROWSE_COPYDLG_H__2487B07B_978D_4A9E_957C_8E78D6EEAC4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetWork_Browse_CopyDlg dialog

class CNetWork_Browse_CopyDlg : public CDialog
{
// Construction
public:
	CNetWork_Browse_CopyDlg(CWnd* pParent = NULL);	// standard constructor
	void BrowseDir(CString strDir);
	bool SearchFile(CString strDir,CString strFile);
	void GetLocalFileAmount();
	void CreateNetWorkPath();
	void GetFileName2Memory();
	bool MountNetWorkDir(int intTimer);
	void Timer1Function();
	bool AutomaticDeleteFile();
	CString	m_FileData;
	CString	m_FileName;
	long lngIPDataAmount;
// Dialog Data
	//{{AFX_DATA(CNetWork_Browse_CopyDlg)
	enum { IDD = IDD_NETWORK_BROWSE_COPY_DIALOG };
	CIPAddressCtrl	m_IPData;
	long	m_FileAmount;
	CString	m_StrNetWorkDir;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetWork_Browse_CopyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetWork_Browse_CopyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORK_BROWSE_COPYDLG_H__2487B07B_978D_4A9E_957C_8E78D6EEAC4D__INCLUDED_)
