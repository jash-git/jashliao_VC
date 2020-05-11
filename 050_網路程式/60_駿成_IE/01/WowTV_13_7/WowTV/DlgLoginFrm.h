#if !defined(AFX_DLGLOGINFRM_H__FA95FCA5_D45E_495D_B453_609D5A98917F__INCLUDED_)
#define AFX_DLGLOGINFRM_H__FA95FCA5_D45E_495D_B453_609D5A98917F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLoginFrm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginFrm dialog

class CDlgLoginFrm : public CDialog
{
// Construction
public:
	CDlgLoginFrm(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgLoginFrm)
	enum { IDD = IDD_Login };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLoginFrm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CDlgLoginFrm)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLOGINFRM_H__FA95FCA5_D45E_495D_B453_609D5A98917F__INCLUDED_)
