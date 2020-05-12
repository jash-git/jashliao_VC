// DCView.h : interface of the CDCView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCVIEW_H__546F9EA0_DDAA_42D8_9287_E9361ADC2EA2__INCLUDED_)
#define AFX_DCVIEW_H__546F9EA0_DDAA_42D8_9287_E9361ADC2EA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDCView : public CView
{
protected: // create from serialization only
	CDCView();
	DECLARE_DYNCREATE(CDCView)

// Attributes
public:
	CDCDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDCView)
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
	virtual ~CDCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDCView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DCView.cpp
inline CDCDoc* CDCView::GetDocument()
   { return (CDCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DCVIEW_H__546F9EA0_DDAA_42D8_9287_E9361ADC2EA2__INCLUDED_)
