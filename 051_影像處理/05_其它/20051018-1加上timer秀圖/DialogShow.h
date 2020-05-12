#if !defined(AFX_DIALOGSHOW_H__6837B585_2DA9_491C_AE2C_5504D1D02113__INCLUDED_)
#define AFX_DIALOGSHOW_H__6837B585_2DA9_491C_AE2C_5504D1D02113__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogShow.h : header file
//
#include "DibSection.h"
/////////////////////////////////////////////////////////////////////////////
// CDialogShow dialog

class CDialogShow : public CDialog
{
// Construction
public:
	CDialogShow(CWnd* pParent = NULL);   // standard constructor
	void getvalue(int **p,int w,int h);
// Dialog Data
	//{{AFX_DATA(CDialogShow)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogShow)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogShow)
	afx_msg void OnPaint();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSHOW_H__6837B585_2DA9_491C_AE2C_5504D1D02113__INCLUDED_)
