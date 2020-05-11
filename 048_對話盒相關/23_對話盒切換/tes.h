#if !defined(AFX_TES_H__C8A477B8_CF51_4021_ABB3_7540FCEA469D__INCLUDED_)
#define AFX_TES_H__C8A477B8_CF51_4021_ABB3_7540FCEA469D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tes.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// tes dialog
#include "testDlg.h"
class tes : public CDialog
{
// Construction
public:
	tes(CWnd* pParent = NULL);   // standard constructor
	CTestDlg *pr;
	void getdata(CTestDlg *k);
// Dialog Data
	//{{AFX_DATA(tes)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(tes)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(tes)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TES_H__C8A477B8_CF51_4021_ABB3_7540FCEA469D__INCLUDED_)
