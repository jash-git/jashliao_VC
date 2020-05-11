// test123View.h : interface of the CTest123View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST123VIEW_H__78E08AEF_51F2_4F1A_A026_8694A7D68888__INCLUDED_)
#define AFX_TEST123VIEW_H__78E08AEF_51F2_4F1A_A026_8694A7D68888__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest123View : public CView
{
protected: // create from serialization only
	CTest123View();
	DECLARE_DYNCREATE(CTest123View)

// Attributes
public:
	CTest123Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest123View)
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
	virtual ~CTest123View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest123View)
	afx_msg void Ontest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test123View.cpp
inline CTest123Doc* CTest123View::GetDocument()
   { return (CTest123Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST123VIEW_H__78E08AEF_51F2_4F1A_A026_8694A7D68888__INCLUDED_)
