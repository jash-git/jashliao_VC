// test_versionDlg.h : header file
//

#if !defined(AFX_TEST_VERSIONDLG_H__FB2361B7_3C75_48C8_B293_DBAA9B2F0D1D__INCLUDED_)
#define AFX_TEST_VERSIONDLG_H__FB2361B7_3C75_48C8_B293_DBAA9B2F0D1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_versionDlg dialog

class CTest_versionDlg : public CDialog
{
// Construction
public:
	CTest_versionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_versionDlg)
	enum { IDD = IDD_TEST_VERSION_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_versionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_versionDlg)
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

#endif // !defined(AFX_TEST_VERSIONDLG_H__FB2361B7_3C75_48C8_B293_DBAA9B2F0D1D__INCLUDED_)
