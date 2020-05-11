// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__F5B21A8C_5EE9_11D7_BCB5_CEB29E77AC3D__INCLUDED_)
#define AFX_DLGPROXY_H__F5B21A8C_5EE9_11D7_BCB5_CEB29E77AC3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPlayerDlg;

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlgAutoProxy command target

class CPlayerDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CPlayerDlgAutoProxy)

	CPlayerDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CPlayerDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayerDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPlayerDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CPlayerDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CPlayerDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CPlayerDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__F5B21A8C_5EE9_11D7_BCB5_CEB29E77AC3D__INCLUDED_)
