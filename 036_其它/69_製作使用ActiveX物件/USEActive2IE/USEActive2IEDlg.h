// USEActive2IEDlg.h : header file
//
//{{AFX_INCLUDES()
#include "testactive2ie.h"
//}}AFX_INCLUDES

#if !defined(AFX_USEACTIVE2IEDLG_H__0D02E524_A272_4F43_A98D_AAB433078BFA__INCLUDED_)
#define AFX_USEACTIVE2IEDLG_H__0D02E524_A272_4F43_A98D_AAB433078BFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUSEActive2IEDlg dialog

class CUSEActive2IEDlg : public CDialog
{
// Construction
public:
	CUSEActive2IEDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUSEActive2IEDlg)
	enum { IDD = IDD_USEACTIVE2IE_DIALOG };
	CTestActive2IE	m_testActive2IE;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUSEActive2IEDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUSEActive2IEDlg)
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

#endif // !defined(AFX_USEACTIVE2IEDLG_H__0D02E524_A272_4F43_A98D_AAB433078BFA__INCLUDED_)
