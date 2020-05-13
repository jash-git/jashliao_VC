// Timer_CPP_fstreamDlg.h : header file
//

#if !defined(AFX_TIMER_CPP_FSTREAMDLG_H__D172156B_4C65_42BD_9428_4BCE47F707D9__INCLUDED_)
#define AFX_TIMER_CPP_FSTREAMDLG_H__D172156B_4C65_42BD_9428_4BCE47F707D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTimer_CPP_fstreamDlg dialog

class CTimer_CPP_fstreamDlg : public CDialog
{
// Construction
public:
	CTimer_CPP_fstreamDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTimer_CPP_fstreamDlg)
	enum { IDD = IDD_TIMER_CPP_FSTREAM_DIALOG };
	CButton	m_B1;
	CString	m_V1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimer_CPP_fstreamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimer_CPP_fstreamDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMER_CPP_FSTREAMDLG_H__D172156B_4C65_42BD_9428_4BCE47F707D9__INCLUDED_)
