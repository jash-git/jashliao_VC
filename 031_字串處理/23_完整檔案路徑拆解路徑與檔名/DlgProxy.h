// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__1EE1D044_0BCC_4562_8CF6_B095B259533D__INCLUDED_)
#define AFX_DLGPROXY_H__1EE1D044_0BCC_4562_8CF6_B095B259533D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGetPathAndNameDlg;

/////////////////////////////////////////////////////////////////////////////
// CGetPathAndNameDlgAutoProxy command target

class CGetPathAndNameDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CGetPathAndNameDlgAutoProxy)

	CGetPathAndNameDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CGetPathAndNameDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetPathAndNameDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CGetPathAndNameDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CGetPathAndNameDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CGetPathAndNameDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CGetPathAndNameDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__1EE1D044_0BCC_4562_8CF6_B095B259533D__INCLUDED_)
