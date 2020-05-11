#if !defined(AFX_DLG1_H__CD5B1185_F260_4867_8FA2_652C5A0171B8__INCLUDED_)
#define AFX_DLG1_H__CD5B1185_F260_4867_8FA2_652C5A0171B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// dlg1 dialog
#include "dlg2.h"
class dlg1 : public CDialog
{
// Construction
public:
	dlg1(CWnd* pParent = NULL);   // standard constructor
	dlg2 d2;
// Dialog Data
	//{{AFX_DATA(dlg1)
	enum { IDD = IDD_DIALOG1 };
	int		m_v1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(dlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(dlg1)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG1_H__CD5B1185_F260_4867_8FA2_652C5A0171B8__INCLUDED_)
