// TabDlg.h : header file
//

#if !defined(AFX_TABDLG_H__CA54F6ED_B780_46FA_8047_C55543832B9A__INCLUDED_)
#define AFX_TABDLG_H__CA54F6ED_B780_46FA_8047_C55543832B9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTabDlg dialog

class CTabDlg : public CDialog
{
// Construction
public:
	CTabDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTabDlg)
	enum { IDD = IDD_TAB_DIALOG };
	double	m_v1;
	double	m_v2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTabDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDLG_H__CA54F6ED_B780_46FA_8047_C55543832B9A__INCLUDED_)
