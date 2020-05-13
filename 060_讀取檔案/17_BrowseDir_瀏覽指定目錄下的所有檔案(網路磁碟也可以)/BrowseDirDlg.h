// BrowseDirDlg.h : header file
//

#if !defined(AFX_BROWSEDIRDLG_H__F86BED07_66D8_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_BROWSEDIRDLG_H__F86BED07_66D8_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBrowseDirDlg dialog

class CBrowseDirDlg : public CDialog
{
// Construction
public:
	CBrowseDirDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBrowseDirDlg)
	enum { IDD = IDD_BROWSEDIR_DIALOG };
	CString	m_strDir;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrowseDirDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	void BrowseDir(CString strDir);
	// Generated message map functions
	//{{AFX_MSG(CBrowseDirDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWSEDIRDLG_H__F86BED07_66D8_11D6_8F32_00E04CE76240__INCLUDED_)
