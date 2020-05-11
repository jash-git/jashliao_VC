#if !defined(AFX_MYWND_H__A761190E_CDF2_4A56_8848_AEE5AC7AD160__INCLUDED_)
#define AFX_MYWND_H__A761190E_CDF2_4A56_8848_AEE5AC7AD160__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyWnd window

class CMyWnd : public CWnd
{
// Construction
public:
	CMyWnd();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	void Initialize(LPCTSTR lpszName,CRect &rectWnd,UINT nMaskId,UINT nShowId);
	void Display(CDC *pDC,UINT nMaskId);
	virtual ~CMyWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyWnd)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg UINT OnNcHitTest(CPoint point);

	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	UINT m_nBitmapId;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWND_H__A761190E_CDF2_4A56_8848_AEE5AC7AD160__INCLUDED_)
