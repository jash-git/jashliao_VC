// TopShowView.h : interface of the CTopShowView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOPSHOWVIEW_H__F607772C_2393_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_TOPSHOWVIEW_H__F607772C_2393_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTopShowView : public CView
{
protected: // create from serialization only
	CTopShowView();
	DECLARE_DYNCREATE(CTopShowView)

// Attributes
public:
	CTopShowDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTopShowView)
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
	virtual ~CTopShowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTopShowView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TopShowView.cpp
inline CTopShowDoc* CTopShowView::GetDocument()
   { return (CTopShowDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOPSHOWVIEW_H__F607772C_2393_11DA_B776_0040F43A9B72__INCLUDED_)
