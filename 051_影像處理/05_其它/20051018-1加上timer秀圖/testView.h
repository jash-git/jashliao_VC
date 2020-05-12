// testView.h : interface of the CTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTVIEW_H__AC8DB524_9326_423E_81BE_9F541DB6B892__INCLUDED_)
#define AFX_TESTVIEW_H__AC8DB524_9326_423E_81BE_9F541DB6B892__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "testDoc.h"
#include "DibSection.h"
class CTestView : public CView
{
protected: // create from serialization only
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// Attributes
public:
	CTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestView)
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
	virtual ~CTestView();
	CDibSection testDib;
	CDibSection testDib1;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void Onchange();
	afx_msg void Onchange1();
	afx_msg void Oncopchange();
	afx_msg void Onchangegray();
	afx_msg void OnRgb2cmy();
	afx_msg void OnRgb2hsi1();
	afx_msg void OnRgb2hsi2();
	afx_msg void OnRgb2hsi3();
	afx_msg void Ongrayrulers();
	afx_msg void OnStretch();
	afx_msg void OnEqualization();
	afx_msg void Onsobel();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimerShow();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in testView.cpp
inline CTestDoc* CTestView::GetDocument()
   { return (CTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTVIEW_H__AC8DB524_9326_423E_81BE_9F541DB6B892__INCLUDED_)
