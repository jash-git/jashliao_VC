// SetBkColor_testDlg.h : header file
//

#if !defined(AFX_SETBKCOLOR_TESTDLG_H__CBF0E8A4_46E5_4D83_820C_DB0EE6A874EE__INCLUDED_)
#define AFX_SETBKCOLOR_TESTDLG_H__CBF0E8A4_46E5_4D83_820C_DB0EE6A874EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetBkColor_testDlg dialog

class CSetBkColor_testDlg : public CDialog
{
// Construction
public:
	CSetBkColor_testDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSetBkColor_testDlg)
	enum { IDD = IDD_SETBKCOLOR_TEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetBkColor_testDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSetBkColor_testDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETBKCOLOR_TESTDLG_H__CBF0E8A4_46E5_4D83_820C_DB0EE6A874EE__INCLUDED_)
