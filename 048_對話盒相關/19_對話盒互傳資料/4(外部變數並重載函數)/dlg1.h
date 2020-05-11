#if !defined(AFX_DLG1_H__36F7D7A3_6B97_4DC7_90A3_AB42C0DF6C1A__INCLUDED_)
#define AFX_DLG1_H__36F7D7A3_6B97_4DC7_90A3_AB42C0DF6C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// dlg1 dialog

class dlg1 : public CDialog
{
// Construction
public:
	dlg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(dlg1)
	enum { IDD = IDD_DIALOG1 };
	long	m_v1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(dlg1)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(dlg1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG1_H__36F7D7A3_6B97_4DC7_90A3_AB42C0DF6C1A__INCLUDED_)
