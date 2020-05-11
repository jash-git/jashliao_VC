// ServerGetDataView.h : interface of the CServerGetDataView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVERGETDATAVIEW_H__6B878070_75B3_477C_A47D_D77B2A29529D__INCLUDED_)
#define AFX_SERVERGETDATAVIEW_H__6B878070_75B3_477C_A47D_D77B2A29529D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DibSection.h"
class CServerGetDataView : public CView
{
protected: // create from serialization only
	CServerGetDataView();
	DECLARE_DYNCREATE(CServerGetDataView)
	CDibSection DibBmp1,DibBmp2;
// Attributes
public:
	CServerGetDataDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerGetDataView)
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
	virtual ~CServerGetDataView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CServerGetDataView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ServerGetDataView.cpp
inline CServerGetDataDoc* CServerGetDataView::GetDocument()
   { return (CServerGetDataDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERGETDATAVIEW_H__6B878070_75B3_477C_A47D_D77B2A29529D__INCLUDED_)
