// wed2View.h : interface of the CWed2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WED2VIEW_H__57E6996C_0F7C_11D6_A27B_002018393AA2__INCLUDED_)
#define AFX_WED2VIEW_H__57E6996C_0F7C_11D6_A27B_002018393AA2__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CWed2View : public CView
{
protected: // create from serialization only
	CWed2View();
	DECLARE_DYNCREATE(CWed2View)

// Attributes
public:
	CWed2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWed2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	HGLRC m_hglrc;
	HDC m_hgldc;

	BOOL SetPixelformat(HDC hdc);
	void ReSizeGLScene(int width, int height);
	void GetGLInfo();
	int DrawGLScene(void);
	int InitGL(void);

	float m_zoom,
		  m_xpos,
		  m_ypos,
		  m_xrot,
		  m_yrot;
	int	  m_lastMouseX,
		  m_lastMouseY;
	
	
	virtual ~CWed2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWed2View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in wed2View.cpp
inline CWed2Doc* CWed2View::GetDocument()
   { return (CWed2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WED2VIEW_H__57E6996C_0F7C_11D6_A27B_002018393AA2__INCLUDED_)
