#if !defined(AFX_GRIBBLEWND_H__6E1D4ED1_D9A6_11D4_9B9F_525400DAE6A0__INCLUDED_)
#define AFX_GRIBBLEWND_H__6E1D4ED1_D9A6_11D4_9B9F_525400DAE6A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GribbleWnd.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CGribbleWnd window

class CGribbleWnd : public CWnd
{
// Construction
public:
	CGribbleWnd();

// Attributes
public:
    // screen stuff
    int         m_pixelsX;
    int         m_pixelsY;
    int         m_bitsPixel;

    // our very own device context  -  assumes window created with a class that has OWNDC set
    CDC*        m_pDC;

    // ...and our very own cursor even!
    HCURSOR m_hCursor; 

    // hows about a nice background brush color...
    COLORREF    m_backColor;


// Operations

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGribbleWnd)
	//}}AFX_VIRTUAL

// Implementation
	virtual ~CGribbleWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CGribbleWnd)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRIBBLEWND_H__6E1D4ED1_D9A6_11D4_9B9F_525400DAE6A0__INCLUDED_)
