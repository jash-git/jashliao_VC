// test_NetWork_FileDlg.h : header file
//

#if !defined(AFX_TEST_NETWORK_FILEDLG_H__1BBF8B90_D0C3_49D8_9931_E852DAF0FD03__INCLUDED_)
#define AFX_TEST_NETWORK_FILEDLG_H__1BBF8B90_D0C3_49D8_9931_E852DAF0FD03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_NetWork_FileDlg dialog

class CTest_NetWork_FileDlg : public CDialog
{
// Construction
public:
	CTest_NetWork_FileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_NetWork_FileDlg)
	enum { IDD = IDD_TEST_NETWORK_FILE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_NetWork_FileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_NetWork_FileDlg)
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

#endif // !defined(AFX_TEST_NETWORK_FILEDLG_H__1BBF8B90_D0C3_49D8_9931_E852DAF0FD03__INCLUDED_)
