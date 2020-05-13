// test_MutiGetValueDlg.h : header file
//

#if !defined(AFX_TEST_MUTIGETVALUEDLG_H__EBC5172E_F149_42A4_B308_FDDB71E7BF32__INCLUDED_)
#define AFX_TEST_MUTIGETVALUEDLG_H__EBC5172E_F149_42A4_B308_FDDB71E7BF32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_MutiGetValueDlg dialog

class CTest_MutiGetValueDlg : public CDialog
{
// Construction
public:
	CTest_MutiGetValueDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_MutiGetValueDlg)
	enum { IDD = IDD_TEST_MUTIGETVALUE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_MutiGetValueDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_MutiGetValueDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_MUTIGETVALUEDLG_H__EBC5172E_F149_42A4_B308_FDDB71E7BF32__INCLUDED_)
