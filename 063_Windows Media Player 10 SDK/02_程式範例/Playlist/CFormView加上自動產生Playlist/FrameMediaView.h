// FrameMediaView.h : interface of the CFrameMediaView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
//}}AFX_INCLUDES

#if !defined(AFX_FRAMEMEDIAVIEW_H__40758ED4_FD89_42AB_B7DC_A0F5650AA3C2__INCLUDED_)
#define AFX_FRAMEMEDIAVIEW_H__40758ED4_FD89_42AB_B7DC_A0F5650AA3C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFrameMediaView : public CFormView
{
protected: // create from serialization only
	CFrameMediaView();
	DECLARE_DYNCREATE(CFrameMediaView)

public:
	//{{AFX_DATA(CFrameMediaView)
	enum { IDD = IDD_FRAMEMEDIA_FORM };
	CWMPPlayer4	m_WMP;
	CString	m_v3;
	//}}AFX_DATA

// Attributes
public:
	CFrameMediaDoc* GetDocument();
	int m_FileAmount;
	void BrowseDir(CString strDir);
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrameMediaView)
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
	virtual ~CFrameMediaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFrameMediaView)
	afx_msg void Ontest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FrameMediaView.cpp
inline CFrameMediaDoc* CFrameMediaView::GetDocument()
   { return (CFrameMediaDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAMEMEDIAVIEW_H__40758ED4_FD89_42AB_B7DC_A0F5650AA3C2__INCLUDED_)
