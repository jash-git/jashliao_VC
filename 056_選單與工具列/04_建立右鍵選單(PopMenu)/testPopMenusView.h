// testPopMenusView.h : interface of the CTestPopMenusView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTPOPMENUSVIEW_H__294E9CA0_8646_467F_A1BB_FEF0BCBE7CF4__INCLUDED_)
#define AFX_TESTPOPMENUSVIEW_H__294E9CA0_8646_467F_A1BB_FEF0BCBE7CF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestPopMenusView : public CView
{
protected: // create from serialization only
	CTestPopMenusView();
	DECLARE_DYNCREATE(CTestPopMenusView)

// Attributes
public:
	CTestPopMenusDoc* GetDocument();
	CMenu *pPopMenu;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestPopMenusView)
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
	virtual ~CTestPopMenusView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestPopMenusView)
	afx_msg void OnPop1();
	afx_msg void OnPop2();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in testPopMenusView.cpp
inline CTestPopMenusDoc* CTestPopMenusView::GetDocument()
   { return (CTestPopMenusDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPOPMENUSVIEW_H__294E9CA0_8646_467F_A1BB_FEF0BCBE7CF4__INCLUDED_)
