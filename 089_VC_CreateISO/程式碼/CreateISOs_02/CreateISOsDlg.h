// CreateISOsDlg.h : header file
//

#if !defined(AFX_CREATEISOSDLG_H__71CB1E7B_C098_43BF_8A5C_6F18387F0239__INCLUDED_)
#define AFX_CREATEISOSDLG_H__71CB1E7B_C098_43BF_8A5C_6F18387F0239__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateISOsDlg dialog

class CCreateISOsDlg : public CDialog
{
// Construction
public:
	CCreateISOsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateISOsDlg)
	enum { IDD = IDD_CREATEISOS_DIALOG };
	CString	m_CStrSou;
	CString	m_CStrISO;
	long	m_lngCount;
	long	m_lngNow;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateISOsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateISOsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreate();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEISOSDLG_H__71CB1E7B_C098_43BF_8A5C_6F18387F0239__INCLUDED_)
