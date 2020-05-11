// TestGLView.h : interface of the CTestGLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTGLVIEW_H__FAA06E26_FFB2_4FB1_AE42_49F0287B541A__INCLUDED_)
#define AFX_TESTGLVIEW_H__FAA06E26_FFB2_4FB1_AE42_49F0287B541A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestGLView : public CView
{
protected: // create from serialization only
	CTestGLView();
	DECLARE_DYNCREATE(CTestGLView)

// Attributes
public:
	CTestGLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestGLView)
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
	virtual ~CTestGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestGLView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TestGLView.cpp
inline CTestGLDoc* CTestGLView::GetDocument()
   { return (CTestGLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTGLVIEW_H__FAA06E26_FFB2_4FB1_AE42_49F0287B541A__INCLUDED_)
