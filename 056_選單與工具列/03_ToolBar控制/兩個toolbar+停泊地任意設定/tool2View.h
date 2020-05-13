// tool2View.h : interface of the CTool2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOL2VIEW_H__5EA4A3EC_211C_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_TOOL2VIEW_H__5EA4A3EC_211C_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTool2View : public CView
{
protected: // create from serialization only
	CTool2View();
	DECLARE_DYNCREATE(CTool2View)

// Attributes
public:
	CTool2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTool2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTool2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTool2View)
	afx_msg void OnBu1();
	afx_msg void OnBu2();
	afx_msg void OnBu3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in tool2View.cpp
inline CTool2Doc* CTool2View::GetDocument()
   { return (CTool2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOL2VIEW_H__5EA4A3EC_211C_11DA_B776_0040F43A9B72__INCLUDED_)
