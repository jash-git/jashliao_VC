// test_Set_IPDlg.h : header file
//

#if !defined(AFX_TEST_SET_IPDLG_H__EA048E9F_0912_46F3_82C6_3045579B5B26__INCLUDED_)
#define AFX_TEST_SET_IPDLG_H__EA048E9F_0912_46F3_82C6_3045579B5B26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_Set_IPDlg dialog

class CTest_Set_IPDlg : public CDialog
{
// Construction
public:
	CTest_Set_IPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_Set_IPDlg)
	enum { IDD = IDD_TEST_SET_IP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Set_IPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_Set_IPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_SET_IPDLG_H__EA048E9F_0912_46F3_82C6_3045579B5B26__INCLUDED_)
