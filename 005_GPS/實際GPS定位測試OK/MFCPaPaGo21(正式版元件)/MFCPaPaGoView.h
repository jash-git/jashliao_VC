// MFCPaPaGoView.h : interface of the CMFCPaPaGoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCPAPAGOVIEW_H__8233E6DB_DB31_4D6C_8E72_703E7708F66E__INCLUDED_)
#define AFX_MFCPAPAGOVIEW_H__8233E6DB_DB31_4D6C_8E72_703E7708F66E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "bmpsdkv5.h"
#include "ppgsdk50.h"
#include "DibSection.h"
#include "ShowGPSData.h"
#include "PaPaGoString.h"
#include "RS232.h"
class CMFCPaPaGoView : public CView
{
protected: // create from serialization only
	CMFCPaPaGoView();
	DECLARE_DYNCREATE(CMFCPaPaGoView)

// Attributes
public:
	CMFCPaPaGoDoc* GetDocument();
	int StringRipFunction(unsigned char str[],long number);
	///////////////////////////////GPS start
	CShowGPSData SGD;
	CRS232 RS;
	CPaPaGoString PaPaGo;
	CString	m_Input;
	CString	m_head;
	CString	m_time;
	CString	m_strLatitude;
	CString	m_strLongitude;
	CString	m_direction;
	int		m_DataOK;
	long	m_X1;
	long	m_Y1;
	double	m_fltRate;
	////////////////////////////GPS end
	long m_lngGisX,m_lngGisY;
	HRESULT hr;//1
	HRESULT hrRoute;//1
	IMapObject *gpMapEngine;//2一般顯示地圖用
	IMapObject *gpMapEngineRoute;//2一般顯示地圖用
	bool blnLoadMap;
	bool bnlShowBmp;
	long lngMoveIndex;
	void MapUp(void);
	void MapDown(void);
	void MapRight(void);
	void MapLeft(void);
	void center(void);
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCPaPaGoView)
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
	virtual ~CMFCPaPaGoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCPaPaGoView)
	afx_msg void OnLoadMap();
	afx_msg void OnUpmap();
	afx_msg void OnDownmap();
	afx_msg void OnLeftmap();
	afx_msg void OnRightmap();
	afx_msg void OnCenter();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRuntimer();
	afx_msg void OnDirectBMP();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRouting();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCPaPaGoView.cpp
inline CMFCPaPaGoDoc* CMFCPaPaGoView::GetDocument()
   { return (CMFCPaPaGoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCPAPAGOVIEW_H__8233E6DB_DB31_4D6C_8E72_703E7708F66E__INCLUDED_)
