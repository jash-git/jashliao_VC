// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__5E5CFD8B_2210_46BE_A753_F4A5B0EDAED9__INCLUDED_)
#define AFX_DLGPROXY_H__5E5CFD8B_2210_46BE_A753_F4A5B0EDAED9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMFC_sscanf_proDlg;

/////////////////////////////////////////////////////////////////////////////
// CMFC_sscanf_proDlgAutoProxy command target

class CMFC_sscanf_proDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CMFC_sscanf_proDlgAutoProxy)

	CMFC_sscanf_proDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CMFC_sscanf_proDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_sscanf_proDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMFC_sscanf_proDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CMFC_sscanf_proDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CMFC_sscanf_proDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CMFC_sscanf_proDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__5E5CFD8B_2210_46BE_A753_F4A5B0EDAED9__INCLUDED_)
