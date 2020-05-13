// MenuCtrlView.h : interface of the CMenuCtrlView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENUCTRLVIEW_H__E278718C_2F34_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_MENUCTRLVIEW_H__E278718C_2F34_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMenuCtrlView : public CView
{
protected: // create from serialization only
	CMenuCtrlView();
	DECLARE_DYNCREATE(CMenuCtrlView)

// Attributes
public:
	CMenuCtrlDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuCtrlView)
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
	virtual ~CMenuCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenuCtrlView)
	afx_msg void Ontest1();
	afx_msg void OnUpdatetest1(CCmdUI* pCmdUI);
	afx_msg void Ontest2();
	afx_msg void OnUpdatetest2(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MenuCtrlView.cpp
inline CMenuCtrlDoc* CMenuCtrlView::GetDocument()
   { return (CMenuCtrlDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUCTRLVIEW_H__E278718C_2F34_11DA_B776_0040F43A9B72__INCLUDED_)
