// ChildFrm.h : interface of the CChildFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDFRM_H__3708734D_9113_487A_AA5B_45E3A25950F4__INCLUDED_)
#define AFX_CHILDFRM_H__3708734D_9113_487A_AA5B_45E3A25950F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildFrame)
	//}}AFX_VIRTUAL

// Generated message map functions
protected:
	//{{AFX_MSG(CChildFrame)
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDFRM_H__3708734D_9113_487A_AA5B_45E3A25950F4__INCLUDED_)
