// test_ctrlDlg.h : header file
//

#if !defined(AFX_TEST_CTRLDLG_H__ADD1F07B_7734_4C66_BF75_4B6CD587B703__INCLUDED_)
#define AFX_TEST_CTRLDLG_H__ADD1F07B_7734_4C66_BF75_4B6CD587B703__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_ctrlDlg dialog

class CTest_ctrlDlg : public CDialog
{
// Construction
public:
	CTest_ctrlDlg(CWnd* pParent = NULL);	// standard constructor
	afx_msg void On_click0();
	afx_msg void On_click1();
	afx_msg void On_click2();
	afx_msg void On_click3();
	afx_msg void On_click4();
	afx_msg void On_click5();
	afx_msg void On_click6();
	afx_msg void On_click7();
	afx_msg void On_click8();
	afx_msg void On_click9();
// Dialog Data
	//{{AFX_DATA(CTest_ctrlDlg)
	enum { IDD = IDD_TEST_CTRL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_ctrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_ctrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_CTRLDLG_H__ADD1F07B_7734_4C66_BF75_4B6CD587B703__INCLUDED_)
