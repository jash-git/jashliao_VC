// test_Show_Hide_CursorDlg.h : header file
//

#if !defined(AFX_TEST_SHOW_HIDE_CURSORDLG_H__C57FAE52_9BF4_4091_B7CD_651F322433BA__INCLUDED_)
#define AFX_TEST_SHOW_HIDE_CURSORDLG_H__C57FAE52_9BF4_4091_B7CD_651F322433BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_Show_Hide_CursorDlg dialog

class CTest_Show_Hide_CursorDlg : public CDialog
{
// Construction
public:
	CTest_Show_Hide_CursorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_Show_Hide_CursorDlg)
	enum { IDD = IDD_TEST_SHOW_HIDE_CURSOR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Show_Hide_CursorDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_Show_Hide_CursorDlg)
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

#endif // !defined(AFX_TEST_SHOW_HIDE_CURSORDLG_H__C57FAE52_9BF4_4091_B7CD_651F322433BA__INCLUDED_)
