// zipdlgDlg.h : header file
//

#if !defined(AFX_ZIPDLGDLG_H__553DDFE8_1BD5_11D5_9158_0020183C9DA9__INCLUDED_)
#define AFX_ZIPDLGDLG_H__553DDFE8_1BD5_11D5_9158_0020183C9DA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CZipdlgDlg dialog

class CZipdlgDlg : public CDialog
{
// Construction
public:
	CZipdlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZipdlgDlg)
	enum { IDD = IDD_ZIPDLG_DIALOG };
	CString	m_fileforzip;
	CString	m_newfilename;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZipdlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZipdlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBrowsefileforzip();
	afx_msg void OnZipit();
	afx_msg void OnExtract();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZIPDLGDLG_H__553DDFE8_1BD5_11D5_9158_0020183C9DA9__INCLUDED_)
