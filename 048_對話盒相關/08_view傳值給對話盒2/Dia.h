#if !defined(AFX_DIA_H__A5455655_D97D_4CA3_BC0C_C766232A753C__INCLUDED_)
#define AFX_DIA_H__A5455655_D97D_4CA3_BC0C_C766232A753C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dia.h : header file
//
//#include "TESTView.h"
/////////////////////////////////////////////////////////////////////////////
// CDia dialog

class CDia : public CDialog
{
// Construction
public:
	CDia(CWnd* pParent = NULL);   // standard constructor
	void show(int a);
// Dialog Data
	//{{AFX_DATA(CDia)
	enum { IDD = IDD_DIALOG1 };
	int		m_v1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDia)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDia)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIA_H__A5455655_D97D_4CA3_BC0C_C766232A753C__INCLUDED_)
