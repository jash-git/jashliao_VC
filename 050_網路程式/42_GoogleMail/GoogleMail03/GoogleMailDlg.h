// GoogleMailDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_GOOGLEMAILDLG_H__03F0C76C_5A3E_44AE_8AC5_A2E308B08EEF__INCLUDED_)
#define AFX_GOOGLEMAILDLG_H__03F0C76C_5A3E_44AE_8AC5_A2E308B08EEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGoogleMailDlg dialog

class CGoogleMailDlg : public CDialog
{
// Construction
public:
	CGoogleMailDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGoogleMailDlg)
	enum { IDD = IDD_GOOGLEMAIL_DIALOG };
	CWebBrowser2	m_Web;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoogleMailDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGoogleMailDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT onShowTask(WPARAM wParam,LPARAM lParam); //Step 4
	afx_msg void OnClose();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOOGLEMAILDLG_H__03F0C76C_5A3E_44AE_8AC5_A2E308B08EEF__INCLUDED_)
