// GLbaseView.h : interface of the CGLbaseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLBASEVIEW_H__CA6432EC_29B3_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_GLBASEVIEW_H__CA6432EC_29B3_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Bar.h"
class CGLbaseView : public CView
{
protected: // create from serialization only
	CGLbaseView();
	DECLARE_DYNCREATE(CGLbaseView)

// Attributes
public:
	CBar bar1;
	CGLbaseDoc* GetDocument();
	CClientDC		*dc;//第二步
	HGLRC		m_hrc;		///< OpenGL rendering context
    CPalette *	m_pPal;		///< palette
	void opengl_Initial();//第八步
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGLbaseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGLbaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGLbaseView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void Onset();
	afx_msg void OnButton1();
	afx_msg void OnQ();
	afx_msg void OnS();
	afx_msg void OnW();
	afx_msg void OnX();
	afx_msg void OnZ();
	afx_msg void OnE();
	afx_msg void OnD();
	afx_msg void OnC();
	afx_msg void OnA();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GLbaseView.cpp
inline CGLbaseDoc* CGLbaseView::GetDocument()
   { return (CGLbaseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLBASEVIEW_H__CA6432EC_29B3_11DA_B776_0040F43A9B72__INCLUDED_)
