#if !defined(AFX_VIEW1_H__E95986D9_5354_4857_AE6B_DB88F991D4D6__INCLUDED_)
#define AFX_VIEW1_H__E95986D9_5354_4857_AE6B_DB88F991D4D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// view1.h : header file
//
#include "bar.h"
/////////////////////////////////////////////////////////////////////////////
// view1 view

class view1 : public CView
{
protected:
	view1();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(view1)
	bar bar1;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(view1)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~view1();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(view1)
	afx_msg void Onbar();
	afx_msg void Onshow();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW1_H__E95986D9_5354_4857_AE6B_DB88F991D4D6__INCLUDED_)
