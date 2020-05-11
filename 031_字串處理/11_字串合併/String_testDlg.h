// String_testDlg.h : header file
//

#if !defined(AFX_STRING_TESTDLG_H__8979FC08_DEDA_47FD_BEE0_F4C06148E539__INCLUDED_)
#define AFX_STRING_TESTDLG_H__8979FC08_DEDA_47FD_BEE0_F4C06148E539__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CString_testDlg dialog

class CString_testDlg : public CDialog
{
// Construction
public:
	CString_testDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CString_testDlg)
	enum { IDD = IDD_STRING_TEST_DIALOG };
	CString	m_str1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CString_testDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CString_testDlg)
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

#endif // !defined(AFX_STRING_TESTDLG_H__8979FC08_DEDA_47FD_BEE0_F4C06148E539__INCLUDED_)
