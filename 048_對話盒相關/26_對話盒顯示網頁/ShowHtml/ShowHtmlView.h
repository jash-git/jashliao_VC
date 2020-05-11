// ShowHtmlView.h : interface of the CShowHtmlView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWHTMLVIEW_H__6866564D_7E11_11D7_886E_8A3E70C5F33E__INCLUDED_)
#define AFX_SHOWHTMLVIEW_H__6866564D_7E11_11D7_886E_8A3E70C5F33E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowHtmlView : public CView
{
protected: // create from serialization only
	CShowHtmlView();
	DECLARE_DYNCREATE(CShowHtmlView)

// Attributes
public:
	CShowHtmlDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowHtmlView)
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
	virtual ~CShowHtmlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowHtmlView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShowHtmlView.cpp
inline CShowHtmlDoc* CShowHtmlView::GetDocument()
   { return (CShowHtmlDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWHTMLVIEW_H__6866564D_7E11_11D7_886E_8A3E70C5F33E__INCLUDED_)
