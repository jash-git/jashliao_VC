// test_ChangeDesktopDlg.h : header file
//

#if !defined(AFX_TEST_CHANGEDESKTOPDLG_H__8D65B120_4FC5_48D5_BEBD_94CA11AECFCC__INCLUDED_)
#define AFX_TEST_CHANGEDESKTOPDLG_H__8D65B120_4FC5_48D5_BEBD_94CA11AECFCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_ChangeDesktopDlg dialog

class CTest_ChangeDesktopDlg : public CDialog
{
// Construction
public:
	CTest_ChangeDesktopDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_ChangeDesktopDlg)
	enum { IDD = IDD_TEST_CHANGEDESKTOP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_ChangeDesktopDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_ChangeDesktopDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_CHANGEDESKTOPDLG_H__8D65B120_4FC5_48D5_BEBD_94CA11AECFCC__INCLUDED_)
