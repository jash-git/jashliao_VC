#if !defined(AFX_DIALOG_SET_H__121B3985_12C2_424A_98A3_0697DFD739B5__INCLUDED_)
#define AFX_DIALOG_SET_H__121B3985_12C2_424A_98A3_0697DFD739B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_set.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dialog_set dialog

class Dialog_set : public CDialog
{
// Construction
public:
	Dialog_set(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dialog_set)
	enum { IDD = IDD_DIALOG1 };
	int		m_set;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dialog_set)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dialog_set)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_SET_H__121B3985_12C2_424A_98A3_0697DFD739B5__INCLUDED_)
