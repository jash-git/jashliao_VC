// test_UIDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_TEST_UIDLG_H__F812EEF0_49B1_4F08_AFCF_8380BB320B22__INCLUDED_)
#define AFX_TEST_UIDLG_H__F812EEF0_49B1_4F08_AFCF_8380BB320B22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_UIDlg dialog

class CTest_UIDlg : public CDialog
{
// Construction
public:
	CTest_UIDlg(CWnd* pParent = NULL);	// standard constructor
	afx_msg void On_click0();
	afx_msg void On_click1();
	afx_msg void On_click2();
	afx_msg void On_click3();
	afx_msg void On_click4();
	afx_msg void On_click5();
	afx_msg void On_click6();
	afx_msg void On_click7();
	afx_msg void On_click8();
	afx_msg void On_click9();
// Dialog Data
	//{{AFX_DATA(CTest_UIDlg)
	enum { IDD = IDD_TEST_UI_DIALOG };
	CWebBrowser2	m_Web;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_UIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_UIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_UIDLG_H__F812EEF0_49B1_4F08_AFCF_8380BB320B22__INCLUDED_)
