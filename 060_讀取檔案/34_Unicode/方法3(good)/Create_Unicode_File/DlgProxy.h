// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__7431043F_B6D0_4973_9BB7_D97CD2E6B9DC__INCLUDED_)
#define AFX_DLGPROXY_H__7431043F_B6D0_4973_9BB7_D97CD2E6B9DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCreate_Unicode_FileDlg;

/////////////////////////////////////////////////////////////////////////////
// CCreate_Unicode_FileDlgAutoProxy command target

class CCreate_Unicode_FileDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CCreate_Unicode_FileDlgAutoProxy)

	CCreate_Unicode_FileDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CCreate_Unicode_FileDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreate_Unicode_FileDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCreate_Unicode_FileDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CCreate_Unicode_FileDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CCreate_Unicode_FileDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CCreate_Unicode_FileDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__7431043F_B6D0_4973_9BB7_D97CD2E6B9DC__INCLUDED_)
