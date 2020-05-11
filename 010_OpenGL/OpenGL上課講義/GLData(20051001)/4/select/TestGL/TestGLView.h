// TestGLView.h : interface of the CTestGLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTGLVIEW_H__FAA06E26_FFB2_4FB1_AE42_49F0287B541A__INCLUDED_)
#define AFX_TESTGLVIEW_H__FAA06E26_FFB2_4FB1_AE42_49F0287B541A__INCLUDED_

#include "LineData.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OpenGLView.h"
#include "LineData.h"

class CTestGLView : public OpenGLView
{
protected: // create from serialization only
	CTestGLView();
	DECLARE_DYNCREATE(CTestGLView)

// Attributes
public:
	CTestGLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestGLView)
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
	void SetSelect(int index,bool selflag);
	void SelectObjName();
	void GLRender();
	virtual ~CTestGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void SelectDraw(int x1, int y1, int x2, int y2, bool selflag);
	int SelectDraw(GLuint *selectBuff, int size, int cx, int cy, int wx, int wy);
	int SelectDraw(int cx, int cy, bool selflag);
	BOOL SelWinFlag;
	unsigned long DataNum;
	void SetDataNum(unsigned long num);
	void CreateLineData();
	//{{AFX_MSG(CTestGLView)
	afx_msg void OnViewAll();
	afx_msg void OnViewIso();
	afx_msg void OnViewLeft();
	afx_msg void OnViewMove();
	afx_msg void OnViewBack();
	afx_msg void OnViewBottom();
	afx_msg void OnViewFront();
	afx_msg void OnViewPrev();
	afx_msg void OnViewRight();
	afx_msg void OnViewRotate();
	afx_msg void OnViewScale();
	afx_msg void OnViewTop();
	afx_msg void OnViewWindow();
	afx_msg void OnUpdateViewRotate(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewScale(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewWindow(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewMove(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	LineData *LineRecord;
};

#ifndef _DEBUG  // debug version in TestGLView.cpp
inline CTestGLDoc* CTestGLView::GetDocument()
   { return (CTestGLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTGLVIEW_H__FAA06E26_FFB2_4FB1_AE42_49F0287B541A__INCLUDED_)
