// showfontView.h : interface of the CShowfontView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWFONTVIEW_H__173F4B2C_A03D_4A87_87E6_CB5E4A291374__INCLUDED_)
#define AFX_SHOWFONTVIEW_H__173F4B2C_A03D_4A87_87E6_CB5E4A291374__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowfontView : public CView
{
protected: // create from serialization only
	CShowfontView();
	DECLARE_DYNCREATE(CShowfontView)

// Attributes
public:
	CShowfontDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowfontView)
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
	virtual ~CShowfontView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowfontView)
	afx_msg void OnBut1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in showfontView.cpp
inline CShowfontDoc* CShowfontView::GetDocument()
   { return (CShowfontDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWFONTVIEW_H__173F4B2C_A03D_4A87_87E6_CB5E4A291374__INCLUDED_)
