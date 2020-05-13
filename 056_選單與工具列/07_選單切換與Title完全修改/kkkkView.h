// kkkkView.h : interface of the CKkkkView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KKKKVIEW_H__D642A6DD_F5F0_4C1F_9EF0_45442F523038__INCLUDED_)
#define AFX_KKKKVIEW_H__D642A6DD_F5F0_4C1F_9EF0_45442F523038__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKkkkView : public CView
{
protected: // create from serialization only
	CKkkkView();
	DECLARE_DYNCREATE(CKkkkView)

// Attributes
public:
	CKkkkDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKkkkView)
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
	virtual ~CKkkkView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKkkkView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in kkkkView.cpp
inline CKkkkDoc* CKkkkView::GetDocument()
   { return (CKkkkDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KKKKVIEW_H__D642A6DD_F5F0_4C1F_9EF0_45442F523038__INCLUDED_)
