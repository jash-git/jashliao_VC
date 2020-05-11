// ShowviewView.h : interface of the CShowviewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWVIEWVIEW_H__4515125B_5711_4174_9682_D35F839CD051__INCLUDED_)
#define AFX_SHOWVIEWVIEW_H__4515125B_5711_4174_9682_D35F839CD051__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "viewbar.h"
class CShowviewView : public CScrollView
{
protected: // create from serialization only
	CShowviewView();
	DECLARE_DYNCREATE(CShowviewView)

// Attributes
public:
	CShowviewDoc* GetDocument();

// Attributes
public:
void test();
viewbar viewbar1;
CPoint ca,cb,ca1,cb1;
CClientDC  *aDC;
	CPoint p1, p2;
	CList <CPoint,CPoint> list1;
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
	//{{AFX_VIRTUAL(CShowviewView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowviewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowviewView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSettimer();
	afx_msg void OnBar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShowviewView.cpp
inline CShowviewDoc* CShowviewView::GetDocument()
   { return (CShowviewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWVIEWVIEW_H__4515125B_5711_4174_9682_D35F839CD051__INCLUDED_)
