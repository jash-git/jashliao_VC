// AlertDlg.h : header file
//

#if !defined(AFX_ALERTDLG_H__74CFEA67_6678_11D6_84BE_CB00B5092942__INCLUDED_)
#define AFX_ALERTDLG_H__74CFEA67_6678_11D6_84BE_CB00B5092942__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAlertDlg dialog
#include <mmsystem.h>

#define WM_NOTIFYICON	WM_USER+5
#define IDI_ICON		0x0005
#define IDT_APPLY		WM_USER+6

class CAlertDlg : public CDialog
{
// Construction
public:
	~CAlertDlg();
	CAlertDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAlertDlg)
	enum { IDD = IDD_ALERT_DIALOG };
	int		m_Interval;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void ShowMessage (void);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAlertDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickApply();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClickHide();
	//}}AFX_MSG
	afx_msg void OnNotifyIcon(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg BOOL OnQueryEndSession();
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALERTDLG_H__74CFEA67_6678_11D6_84BE_CB00B5092942__INCLUDED_)
