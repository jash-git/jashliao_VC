// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__E30FC510_D321_4BF4_B725_74C49C029C0E__INCLUDED_)
#define AFX_DLGPROXY_H__E30FC510_D321_4BF4_B725_74C49C029C0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCreateDelAllDirDlg;

/////////////////////////////////////////////////////////////////////////////
// CCreateDelAllDirDlgAutoProxy command target

class CCreateDelAllDirDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CCreateDelAllDirDlgAutoProxy)

	CCreateDelAllDirDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CCreateDelAllDirDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateDelAllDirDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCreateDelAllDirDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CCreateDelAllDirDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CCreateDelAllDirDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CCreateDelAllDirDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__E30FC510_D321_4BF4_B725_74C49C029C0E__INCLUDED_)
