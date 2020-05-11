// test_ListControlDlg.h : header file
//

#if !defined(AFX_TEST_LISTCONTROLDLG_H__A5830F8D_4231_4D4E_AB45_A84E18F64869__INCLUDED_)
#define AFX_TEST_LISTCONTROLDLG_H__A5830F8D_4231_4D4E_AB45_A84E18F64869__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_ListControlDlg dialog

class CTest_ListControlDlg : public CDialog
{
// Construction
public:
	CTest_ListControlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_ListControlDlg)
	enum { IDD = IDD_TEST_LISTCONTROL_DIALOG };
	CListCtrl	m_ListControl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_ListControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_ListControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_LISTCONTROLDLG_H__A5830F8D_4231_4D4E_AB45_A84E18F64869__INCLUDED_)
