// PortMonitorDlg.h : header file
//

#if !defined(AFX_PORTMONITORDLG_H__DAEBCCD5_C5C8_4F1B_A066_816B4AA095F4__INCLUDED_)
#define AFX_PORTMONITORDLG_H__DAEBCCD5_C5C8_4F1B_A066_816B4AA095F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPortMonitorDlg dialog

class CPortMonitorDlg : public CDialog
{
// Construction
public:
	CPortMonitorDlg(CWnd* pParent = NULL);	// standard constructor
	int m_intCheck;
	HWND m_Video;
	CString m_Path;
	bool blnmp3;
// Dialog Data
	//{{AFX_DATA(CPortMonitorDlg)
	enum { IDD = IDD_PORTMONITOR_DIALOG };
	BOOL	m_V01;
	BOOL	m_V02;
	BOOL	m_V03;
	BOOL	m_V04;
	BOOL	m_V05;
	BOOL	m_V06;
	BOOL	m_V07;
	BOOL	m_V08;
	BOOL	m_V09;
	BOOL	m_V10;
	BOOL	m_V11;
	BOOL	m_V12;
	BOOL	m_V13;
	BOOL	m_V14;
	BOOL	m_V15;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPortMonitorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPortMonitorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT onShowTask(WPARAM wParam,LPARAM lParam); //Step 4
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PORTMONITORDLG_H__DAEBCCD5_C5C8_4F1B_A066_816B4AA095F4__INCLUDED_)
