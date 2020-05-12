// Image1View.h : interface of the CImage1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGE1VIEW_H__15CEB33E_A403_4D0A_83F8_9FAB81FAB797__INCLUDED_)
#define AFX_IMAGE1VIEW_H__15CEB33E_A403_4D0A_83F8_9FAB81FAB797__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Image1Doc.h"

class CImage1View : public CFormView
{
protected: // create from serialization only
	CImage1View();
	DECLARE_DYNCREATE(CImage1View)

public:
	//{{AFX_DATA(CImage1View)
	enum { IDD = IDD_IMAGE1_FORM };
	CSliderCtrl	m_sl1;
	UINT	m_v1;
	//}}AFX_DATA

// Attributes
public:
	CImage1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImage1View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImage1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImage1View)
	afx_msg void OnOutofmemorySlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Image1View.cpp
inline CImage1Doc* CImage1View::GetDocument()
   { return (CImage1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGE1VIEW_H__15CEB33E_A403_4D0A_83F8_9FAB81FAB797__INCLUDED_)
