// viewView.h : interface of the CViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWVIEW_H__57D71B17_6C82_4111_BEF9_B0FBAA475368__INCLUDED_)
#define AFX_VIEWVIEW_H__57D71B17_6C82_4111_BEF9_B0FBAA475368__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CViewView : public CScrollView
{
protected: // create from serialization only
	CViewView();
	DECLARE_DYNCREATE(CViewView)

// Attributes
public:
	CViewDoc* GetDocument();
	long lngtime;
	CPoint p1, p2;
	//CList <CPoint,CPoint> list1;
	CArray <CPoint,CPoint> Array1;
	CClientDC *aDC;	//建立畫布
	void DrawFrame();
	void DrawGrid();
	void LogicalCoor(CPoint * point)
	{
		CPoint Origin = GetScrollPosition();	//取得目前捲軸的位置

		point->x = Origin.x + point->x;	//將點座標轉換為邏輯座標
		point->y = Origin.y + point->y; //將點座標轉換為邏輯座標
	}
	//MyView::PhysicalCoor
	void PhysicalCoor(CPoint *point)
	{
		CPoint Origin = GetScrollPosition();	//取得目前捲軸的位置

		point->x = point->x - Origin.x; 	//將點座標轉換為物理座標
		point->y = point->y - Origin.y; 	//將點座標轉換為物理座標
	}
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual CScrollBar* GetScrollBarCtrl(int nBar) const;
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CViewView)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStartTimer();
	afx_msg void OnStopTimer();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in viewView.cpp
inline CViewDoc* CViewView::GetDocument()
   { return (CViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWVIEW_H__57D71B17_6C82_4111_BEF9_B0FBAA475368__INCLUDED_)
