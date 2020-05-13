// test_Dlg_HidDlg.h : header file
//

#if !defined(AFX_TEST_DLG_HIDDLG_H__E1B1E312_5EAA_4B1E_9A61_DC600934F1D6__INCLUDED_)
#define AFX_TEST_DLG_HIDDLG_H__E1B1E312_5EAA_4B1E_9A61_DC600934F1D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_Dlg_HidDlg dialog

class CTest_Dlg_HidDlg : public CDialog
{
// Construction
public:
	CTest_Dlg_HidDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_Dlg_HidDlg)
	enum { IDD = IDD_TEST_DLG_HID_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Dlg_HidDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_Dlg_HidDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg LRESULT onShowTask(WPARAM wParam,LPARAM lParam); //Step 4
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_DLG_HIDDLG_H__E1B1E312_5EAA_4B1E_9A61_DC600934F1D6__INCLUDED_)
