// FullScreenView.h : interface of the CFullScreenView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FULLSCREENVIEW_H__F5D40DAF_673D_11D7_8890_00C04F4AD348__INCLUDED_)
#define AFX_FULLSCREENVIEW_H__F5D40DAF_673D_11D7_8890_00C04F4AD348__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFullScreenView : public CView
{
protected: // create from serialization only
	CFullScreenView();
	DECLARE_DYNCREATE(CFullScreenView)

// Attributes
public:
	CFullScreenDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullScreenView)
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
	virtual ~CFullScreenView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFullScreenView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FullScreenView.cpp
inline CFullScreenDoc* CFullScreenView::GetDocument()
   { return (CFullScreenDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLSCREENVIEW_H__F5D40DAF_673D_11D7_8890_00C04F4AD348__INCLUDED_)
