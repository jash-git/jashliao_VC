// test_Get_ChangeFormDlg.h : header file
//

#if !defined(AFX_TEST_GET_CHANGEFORMDLG_H__3992048D_E370_4D16_BEC1_B835AECCB04B__INCLUDED_)
#define AFX_TEST_GET_CHANGEFORMDLG_H__3992048D_E370_4D16_BEC1_B835AECCB04B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_Get_ChangeFormDlg dialog

class CTest_Get_ChangeFormDlg : public CDialog
{
// Construction
public:
	CTest_Get_ChangeFormDlg(CWnd* pParent = NULL);	// standard constructor
	void RipData(CString Datainput);
// Dialog Data
	//{{AFX_DATA(CTest_Get_ChangeFormDlg)
	enum { IDD = IDD_TEST_GET_CHANGEFORM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Get_ChangeFormDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_Get_ChangeFormDlg)
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

#endif // !defined(AFX_TEST_GET_CHANGEFORMDLG_H__3992048D_E370_4D16_BEC1_B835AECCB04B__INCLUDED_)
