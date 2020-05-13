// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__BD80BD43_69AB_45C9_A245_37D49741ABC6__INCLUDED_)
#define AFX_DLGPROXY_H__BD80BD43_69AB_45C9_A245_37D49741ABC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDownLoadNowNewsAVDlg;

/////////////////////////////////////////////////////////////////////////////
// CDownLoadNowNewsAVDlgAutoProxy command target

class CDownLoadNowNewsAVDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CDownLoadNowNewsAVDlgAutoProxy)

	CDownLoadNowNewsAVDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CDownLoadNowNewsAVDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownLoadNowNewsAVDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDownLoadNowNewsAVDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CDownLoadNowNewsAVDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CDownLoadNowNewsAVDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CDownLoadNowNewsAVDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__BD80BD43_69AB_45C9_A245_37D49741ABC6__INCLUDED_)
