// test_CString2chrstrDlg.h : header file
//

#if !defined(AFX_TEST_CSTRING2CHRSTRDLG_H__426889B3_399A_411B_A9AC_623CD2EEC949__INCLUDED_)
#define AFX_TEST_CSTRING2CHRSTRDLG_H__426889B3_399A_411B_A9AC_623CD2EEC949__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_CString2chrstrDlg dialog

class CTest_CString2chrstrDlg : public CDialog
{
// Construction
public:
	CTest_CString2chrstrDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_CString2chrstrDlg)
	enum { IDD = IDD_TEST_CSTRING2CHRSTR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_CString2chrstrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_CString2chrstrDlg)
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

#endif // !defined(AFX_TEST_CSTRING2CHRSTRDLG_H__426889B3_399A_411B_A9AC_623CD2EEC949__INCLUDED_)
