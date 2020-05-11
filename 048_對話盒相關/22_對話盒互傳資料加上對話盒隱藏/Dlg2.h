#if !defined(AFX_DLG2_H__FF1BE00E_193C_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_DLG2_H__FF1BE00E_193C_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg2 dialog

class CDlg2 : public CDialog
{
// Construction
public:
	CDlg2(CWnd* pParent = NULL);   // standard constructor
	void setvalue(double);
// Dialog Data
	//{{AFX_DATA(CDlg2)
	enum { IDD = IDD_DIALOG1 };
	double	m_value;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg2)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG2_H__FF1BE00E_193C_11DA_B776_0040F43A9B72__INCLUDED_)
