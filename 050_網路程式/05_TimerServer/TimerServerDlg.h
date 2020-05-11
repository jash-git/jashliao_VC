// TimerServerDlg.h : header file
//

#if !defined(AFX_TIMERSERVERDLG_H__1326EFC4_4525_46F7_A373_B13F1456BF9F__INCLUDED_)
#define AFX_TIMERSERVERDLG_H__1326EFC4_4525_46F7_A373_B13F1456BF9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTimerServerDlg dialog

class CTimerServerDlg : public CDialog
{
// Construction
public:
	CTimerServerDlg(CWnd* pParent = NULL);	// standard constructor
	CSocket m_sockSend;
// Dialog Data
	//{{AFX_DATA(CTimerServerDlg)
	enum { IDD = IDD_TIMERSERVER_DIALOG };
	int		m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimerServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimerServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERSERVERDLG_H__1326EFC4_4525_46F7_A373_B13F1456BF9F__INCLUDED_)
