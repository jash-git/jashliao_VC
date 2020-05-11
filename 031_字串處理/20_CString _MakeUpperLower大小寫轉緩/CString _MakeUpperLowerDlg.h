// CString _MakeUpperLowerDlg.h : header file
//

#if !defined(AFX_CSTRING_MAKEUPPERLOWERDLG_H__9B55C304_0E1C_4C20_B27D_403621D0BC26__INCLUDED_)
#define AFX_CSTRING_MAKEUPPERLOWERDLG_H__9B55C304_0E1C_4C20_B27D_403621D0BC26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCString_MakeUpperLowerDlg dialog

class CCString_MakeUpperLowerDlg : public CDialog
{
// Construction
public:
	CCString_MakeUpperLowerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCString_MakeUpperLowerDlg)
	enum { IDD = IDD_CSTRING_MAKEUPPERLOWER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCString_MakeUpperLowerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCString_MakeUpperLowerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTRING_MAKEUPPERLOWERDLG_H__9B55C304_0E1C_4C20_B27D_403621D0BC26__INCLUDED_)
