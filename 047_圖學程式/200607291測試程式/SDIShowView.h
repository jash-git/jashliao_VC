// SDIShowView.h : interface of the CSDIShowView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDISHOWVIEW_H__FC8CEE06_1707_43AB_A909_9FC12958FC0A__INCLUDED_)
#define AFX_SDISHOWVIEW_H__FC8CEE06_1707_43AB_A909_9FC12958FC0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSDIShowView : public CView
{
protected: // create from serialization only
	CSDIShowView();
	DECLARE_DYNCREATE(CSDIShowView)

// Attributes
public:
	CSDIShowDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDIShowView)
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
	virtual ~CSDIShowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint PointNowBase; 
// Generated message map functions
protected:
	//{{AFX_MSG(CSDIShowView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SDIShowView.cpp
inline CSDIShowDoc* CSDIShowView::GetDocument()
   { return (CSDIShowDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDISHOWVIEW_H__FC8CEE06_1707_43AB_A909_9FC12958FC0A__INCLUDED_)
