#if !defined(AFX_SHOWBMP_H__49E3B6E3_3954_4727_BD39_84E65145C9AA__INCLUDED_)
#define AFX_SHOWBMP_H__49E3B6E3_3954_4727_BD39_84E65145C9AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowBmp.h : header file
//
#include "DibSection.h"
/////////////////////////////////////////////////////////////////////////////
// CShowBmp view

class CShowBmp : public CView
{
protected:
	CShowBmp();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CShowBmp)

// Attributes
public:
	void Data(int Invalue);
	CDibSection Dib1;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowBmp)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CShowBmp();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CShowBmp)
	afx_msg void Onshow1();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void Onshow2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWBMP_H__49E3B6E3_3954_4727_BD39_84E65145C9AA__INCLUDED_)
