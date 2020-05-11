// kk1View.h : interface of the CKk1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KK1VIEW_H__330DBCCF_EF62_46B9_8A4C_89246C76CEF4__INCLUDED_)
#define AFX_KK1VIEW_H__330DBCCF_EF62_46B9_8A4C_89246C76CEF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
///////////////////////
#include "kk1Doc.h"

///////////////////////
class CKk1View : public CScrollView
{
protected: // create from serialization only
	CKk1View();
	CClientDC		*dc;
	void Rend(void);
	DECLARE_DYNCREATE(CKk1View)
	HGLRC	m_hrc;		///< OpenGL rendering context
	CPalette*	m_pPal;	///< palette
// Attributes
public:
	CKk1Doc* GetDocument();
	void Update(int,int,int,int,int,int);
	void draw_child(int);
	void draw_child1(void);
	void draw_child2(void);
	void draw_child3(void);
	void draw_child4(void);
	void opengl_Initial(void);
	void opengl_disc(void);
	void opengl_final(void);
	void opengl_ServoMotor(void);
	void robot(void);
	CPoint ca,cb,ca1,cb1;
	CClientDC  *aDC;
	int dialog_set;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKk1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKk1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKk1View)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void Onsettimer();
	afx_msg void OnDirectly();
	afx_msg void OnFlank();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in kk1View.cpp
inline CKk1Doc* CKk1View::GetDocument()
   { return (CKk1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KK1VIEW_H__330DBCCF_EF62_46B9_8A4C_89246C76CEF4__INCLUDED_)
