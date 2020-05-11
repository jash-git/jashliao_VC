// glView.h : interface of the CGlView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLVIEW_H__E0701226_8C09_40C6_8FF1_4740E7FD7442__INCLUDED_)
#define AFX_GLVIEW_H__E0701226_8C09_40C6_8FF1_4740E7FD7442__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <gl/gl.h>
#include <gl/glu.h>
class CGlView : public CView
{
protected: // create from serialization only
	CGlView();
	DECLARE_DYNCREATE(CGlView)
	HGLRC		m_hrc;		///< OpenGL rendering context
    CPalette *	m_pPal;		///< palette
	CClientDC		*dc;
// Attributes
public:
	CGlDoc* GetDocument();
	void opengl_Initial();
	void joint();
	void a_shank();
	void foot();
	void a_thigh();
	void waist();
	void BWKinematic();
	void FWKinematic();
	void transform();
	// Operations
public:
//////////////////////腰部的向量變數
GLfloat waist_x;
GLfloat waist_y;
GLfloat waist_z;

GLfloat rfoot_x;
GLfloat rfoot_y;
GLfloat rfoot_z;

GLfloat lfoot_x;
GLfloat lfoot_y;
GLfloat lfoot_z;
//////////////////////left1
GLfloat left1;
//////////////////////left2
GLfloat left2;
//////////////////////left3
GLfloat left3;
//////////////////////right1
GLfloat right1;
//////////////////////right2
GLfloat right2;
//////////////////////right
GLfloat right3;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGlView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGlView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void Oninput();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void Onwalkstart();
	afx_msg void OnTt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in glView.cpp
inline CGlDoc* CGlView::GetDocument()
   { return (CGlDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLVIEW_H__E0701226_8C09_40C6_8FF1_4740E7FD7442__INCLUDED_)
