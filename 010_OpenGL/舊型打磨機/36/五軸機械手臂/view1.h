#if !defined(AFX_VIEW1_H__4A2C5B88_0615_4F49_A285_CD90EFD7883C__INCLUDED_)
#define AFX_VIEW1_H__4A2C5B88_0615_4F49_A285_CD90EFD7883C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// view1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// view1 view

class view1 : public CScrollView
{
protected:
	view1();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(view1)

public:
	void test();
// Attributes
public:
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
	//{{AFX_VIRTUAL(view1)
	public:
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~view1();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(view1)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW1_H__4A2C5B88_0615_4F49_A285_CD90EFD7883C__INCLUDED_)
