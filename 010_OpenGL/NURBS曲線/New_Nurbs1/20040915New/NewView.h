// NewView.h : interface of the CNewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWVIEW_H__91D76A1E_7729_48E8_8D28_30D5A6A4FFBA__INCLUDED_)
#define AFX_NEWVIEW_H__91D76A1E_7729_48E8_8D28_30D5A6A4FFBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "viewbar.h"
class CNewView : public CView
{
protected: // create from serialization only
	CNewView();
	DECLARE_DYNCREATE(CNewView)

// Attributes
public:
	CNewDoc* GetDocument();
	CClientDC		*dc;
	viewbar viewbar1;
	HGLRC	m_hrc;		///< OpenGL rendering context
	CPalette*	m_pPal;	///< palette
	GLUnurbsObj *theNurb;
	void opengl_Initial();
	void Base_model();
	void BaseX_model();
	void BaseY_model();
	void left_support();
	void right_support();
	void watchcase_support();
	void jig();
	void Z_axis();
	void Z_Base();
	void main_shaft();
	void motor();
	void jig_fixed();
	///ªü©¾µù¸Ñ(6)
	void FrontRun();
	void FlankRun();
	void Front1Run();
	void Flank1Run();
	///ªü©¾µù¸Ñ(6)
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNewView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnshiftX();
	afx_msg void OnshiftY();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnTimerStart();
	afx_msg void OnshiftZ();
	afx_msg void OnwatchR();
	afx_msg void OnFlank();
	afx_msg void OnFront();
	afx_msg void OnBar();
	afx_msg void OnFront1();
	afx_msg void OnFlank1();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NewView.cpp
inline CNewDoc* CNewView::GetDocument()
   { return (CNewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWVIEW_H__91D76A1E_7729_48E8_8D28_30D5A6A4FFBA__INCLUDED_)
