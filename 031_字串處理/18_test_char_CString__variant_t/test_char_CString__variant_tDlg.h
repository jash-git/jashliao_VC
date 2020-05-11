// test_char_CString__variant_tDlg.h : header file
//

#if !defined(AFX_TEST_CHAR_CSTRING__VARIANT_TDLG_H__4ACD09F0_2F99_4497_B7C0_A2E3390A5EF3__INCLUDED_)
#define AFX_TEST_CHAR_CSTRING__VARIANT_TDLG_H__4ACD09F0_2F99_4497_B7C0_A2E3390A5EF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_char_CString__variant_tDlg dialog

class CTest_char_CString__variant_tDlg : public CDialog
{
// Construction
public:
	CTest_char_CString__variant_tDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_char_CString__variant_tDlg)
	enum { IDD = IDD_TEST_CHAR_CSTRING__VARIANT_T_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_char_CString__variant_tDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_char_CString__variant_tDlg)
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

#endif // !defined(AFX_TEST_CHAR_CSTRING__VARIANT_TDLG_H__4ACD09F0_2F99_4497_B7C0_A2E3390A5EF3__INCLUDED_)
