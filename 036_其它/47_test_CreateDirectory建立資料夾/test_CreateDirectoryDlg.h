// test_CreateDirectoryDlg.h : header file
//

#if !defined(AFX_TEST_CREATEDIRECTORYDLG_H__9740C88D_99D1_43FF_9058_B04AD8AEE981__INCLUDED_)
#define AFX_TEST_CREATEDIRECTORYDLG_H__9740C88D_99D1_43FF_9058_B04AD8AEE981__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_CreateDirectoryDlg dialog

class CTest_CreateDirectoryDlg : public CDialog
{
// Construction
public:
	CTest_CreateDirectoryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_CreateDirectoryDlg)
	enum { IDD = IDD_TEST_CREATEDIRECTORY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_CreateDirectoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_CreateDirectoryDlg)
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

#endif // !defined(AFX_TEST_CREATEDIRECTORYDLG_H__9740C88D_99D1_43FF_9058_B04AD8AEE981__INCLUDED_)
