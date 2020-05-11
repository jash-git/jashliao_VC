// BigControlDlg.h : header file
//

#if !defined(AFX_BIGCONTROLDLG_H__958FBAE6_8FE9_4E46_B5FE_1DDE28AC09EE__INCLUDED_)
#define AFX_BIGCONTROLDLG_H__958FBAE6_8FE9_4E46_B5FE_1DDE28AC09EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBigControlDlg dialog

class CBigControlDlg : public CDialog
{
// Construction
public:
	CBigControlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBigControlDlg)
	enum { IDD = IDD_BIGCONTROL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBigControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBigControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIGCONTROLDLG_H__958FBAE6_8FE9_4E46_B5FE_1DDE28AC09EE__INCLUDED_)
