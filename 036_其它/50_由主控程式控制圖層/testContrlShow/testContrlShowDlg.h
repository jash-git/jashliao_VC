// testContrlShowDlg.h : header file
//

#if !defined(AFX_TESTCONTRLSHOWDLG_H__34D3E487_0EB7_4A19_8035_031A266C433E__INCLUDED_)
#define AFX_TESTCONTRLSHOWDLG_H__34D3E487_0EB7_4A19_8035_031A266C433E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestContrlShowDlg dialog

class CTestContrlShowDlg : public CDialog
{
// Construction
public:
	CTestContrlShowDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestContrlShowDlg)
	enum { IDD = IDD_TESTCONTRLSHOW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestContrlShowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestContrlShowDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCONTRLSHOWDLG_H__34D3E487_0EB7_4A19_8035_031A266C433E__INCLUDED_)
