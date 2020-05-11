// test_Dlg_EscDlg.h : header file
//

#if !defined(AFX_TEST_DLG_ESCDLG_H__BF04AC7A_723A_4FD5_992F_A033A75C36BD__INCLUDED_)
#define AFX_TEST_DLG_ESCDLG_H__BF04AC7A_723A_4FD5_992F_A033A75C36BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_Dlg_EscDlg dialog

class CTest_Dlg_EscDlg : public CDialog
{
// Construction
public:
	CTest_Dlg_EscDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_Dlg_EscDlg)
	enum { IDD = IDD_TEST_DLG_ESC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Dlg_EscDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_Dlg_EscDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_DLG_ESCDLG_H__BF04AC7A_723A_4FD5_992F_A033A75C36BD__INCLUDED_)
