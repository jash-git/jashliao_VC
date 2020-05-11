// VFWView.h : interface of the CVFWView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VFWVIEW_H__F401699F_13DA_4B63_B9B5_31883831F3CC__INCLUDED_)
#define AFX_VFWVIEW_H__F401699F_13DA_4B63_B9B5_31883831F3CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVFWView : public CView
{
protected: // create from serialization only
	CVFWView();
	DECLARE_DYNCREATE(CVFWView)

// Attributes
public:
	CVFWDoc* GetDocument();
	HWND m_hWndCap;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVFWView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVFWView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVFWView)
	afx_msg void OnGetNumber();
	afx_msg void OnGet();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VFWView.cpp
inline CVFWDoc* CVFWView::GetDocument()
   { return (CVFWDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VFWVIEW_H__F401699F_13DA_4B63_B9B5_31883831F3CC__INCLUDED_)
