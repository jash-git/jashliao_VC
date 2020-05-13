// mouseView.h : interface of the CMouseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOUSEVIEW_H__C02856A8_249A_4329_8BBE_06EB16FA4290__INCLUDED_)
#define AFX_MOUSEVIEW_H__C02856A8_249A_4329_8BBE_06EB16FA4290__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMouseView : public CView
{
protected: // create from serialization only
	CMouseView();
	DECLARE_DYNCREATE(CMouseView)

// Attributes
public:
	CMouseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseView)
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
	virtual ~CMouseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMouseView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mouseView.cpp
inline CMouseDoc* CMouseView::GetDocument()
   { return (CMouseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEVIEW_H__C02856A8_249A_4329_8BBE_06EB16FA4290__INCLUDED_)
