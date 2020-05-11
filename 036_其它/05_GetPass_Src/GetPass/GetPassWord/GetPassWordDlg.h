// GetPassWordDlg.h : header file
//

#if !defined(AFX_GETPASSWORDDLG_H__958CF9E0_A03F_4248_A432_A260117669B4__INCLUDED_)
#define AFX_GETPASSWORDDLG_H__958CF9E0_A03F_4248_A432_A260117669B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GetPassHook.h"

/////////////////////////////////////////////////////////////////////////////
// CGetPassWordDlg dialog

class CGetPassWordDlg : public CDialog
{
// Construction
public:
	CGetPassWordDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetPassWordDlg)
	enum { IDD = IDD_GETPASSWORD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetPassWordDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CXInfoTip m_tip;
	CGetPassHook m_hook;
	// Generated message map functions
	//{{AFX_MSG(CGetPassWordDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETPASSWORDDLG_H__958CF9E0_A03F_4248_A432_A260117669B4__INCLUDED_)
