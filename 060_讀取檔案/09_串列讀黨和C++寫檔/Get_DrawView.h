// Get_DrawView.h : interface of the CGet_DrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GET_DRAWVIEW_H__AE4618BE_60D8_4C30_BBD2_20C0F5E598A0__INCLUDED_)
#define AFX_GET_DRAWVIEW_H__AE4618BE_60D8_4C30_BBD2_20C0F5E598A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGet_DrawView : public CView
{
protected: // create from serialization only
	CGet_DrawView();
	DECLARE_DYNCREATE(CGet_DrawView)

// Attributes
public:
	CGet_DrawDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGet_DrawView)
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
	virtual ~CGet_DrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGet_DrawView)
	afx_msg void Ontest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Get_DrawView.cpp
inline CGet_DrawDoc* CGet_DrawView::GetDocument()
   { return (CGet_DrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GET_DRAWVIEW_H__AE4618BE_60D8_4C30_BBD2_20C0F5E598A0__INCLUDED_)
