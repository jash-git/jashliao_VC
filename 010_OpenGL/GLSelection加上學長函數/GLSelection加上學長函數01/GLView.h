// GLView.h : interface of the CGLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLVIEW_H__B2996431_1A48_492F_87B8_D8E922845B95__INCLUDED_)
#define AFX_GLVIEW_H__B2996431_1A48_492F_87B8_D8E922845B95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGLView : public CView
{
protected: // create from serialization only
	CGLView();
	DECLARE_DYNCREATE(CGLView)

// Attributes
public:
	CGLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGLView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual void RenderScene();

	virtual ~CGLView();

protected:

	void ProcessSelection(int xPos,int yPos);

// Generated message map functions
protected:
	//{{AFX_MSG(CGLView)
	afx_msg int	 OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void		GLInit();
	void		GLRelease();
	void		GLResize(int cx,int cy);
	void		GLSetupRC();

	HGLRC		m_hRC;		//rendering context
	HDC			m_hDC;		//device context
};

#ifndef _DEBUG  // debug version in GLView.cpp
inline CGLDoc* CGLView::GetDocument()
   { return (CGLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLVIEW_H__B2996431_1A48_492F_87B8_D8E922845B95__INCLUDED_)
