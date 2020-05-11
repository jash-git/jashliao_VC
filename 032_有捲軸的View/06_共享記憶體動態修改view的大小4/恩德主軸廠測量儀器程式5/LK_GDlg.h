// LK_GDlg.h : header file
//

#if !defined(AFX_LK_GDLG_H__647A2814_9D70_41A0_9FA8_EE65F2813849__INCLUDED_)
#define AFX_LK_GDLG_H__647A2814_9D70_41A0_9FA8_EE65F2813849__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLK_GDlg dialog

class CLK_GDlg : public CDialog
{
// Construction
public:
	CLK_GDlg(CWnd* pParent = NULL);	// standard constructor
	~CLK_GDlg();
// Dialog Data
	//{{AFX_DATA(CLK_GDlg)
	enum { IDD = IDD_LK_G_DIALOG };
	CString	Send;
	CString	Rce;
	double	m_timer;
	CString	m_Data;
	double	m_v1;
	CString	m_wide;
	CString	m_hight;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLK_GDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HANDLE hCom1;
	DCB dcb;
	COMMTIMEOUTS TimeOuts;
	// Generated message map functions
	//{{AFX_MSG(CLK_GDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenCom();
	afx_msg void OnSendMsg();
	afx_msg void OnReceiveMsg();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnTimerReceive();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LK_GDLG_H__647A2814_9D70_41A0_9FA8_EE65F2813849__INCLUDED_)
