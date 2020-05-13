// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__7ABB4736_BA99_4031_AA13_D26942D9CCC6__INCLUDED_)
#define AFX_DLGPROXY_H__7ABB4736_BA99_4031_AA13_D26942D9CCC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGetNowNewsAVDlg;

/////////////////////////////////////////////////////////////////////////////
// CGetNowNewsAVDlgAutoProxy command target

class CGetNowNewsAVDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CGetNowNewsAVDlgAutoProxy)

	CGetNowNewsAVDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CGetNowNewsAVDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetNowNewsAVDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CGetNowNewsAVDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CGetNowNewsAVDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CGetNowNewsAVDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CGetNowNewsAVDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__7ABB4736_BA99_4031_AA13_D26942D9CCC6__INCLUDED_)
