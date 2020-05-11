// Maping_serverDlg.h : header file
//

#if !defined(AFX_MAPING_SERVERDLG_H__0F3E227A_8CB5_47BE_8841_F4EE934891BE__INCLUDED_)
#define AFX_MAPING_SERVERDLG_H__0F3E227A_8CB5_47BE_8841_F4EE934891BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMaping_serverDlg dialog

class CMaping_serverDlg : public CDialog
{
// Construction
public:
	CMaping_serverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMaping_serverDlg)
	enum { IDD = IDD_MAPING_SERVER_DIALOG };
	double	m_v1;
	double	m_v2;
	double	m_v3;
	double	m_v4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMaping_serverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMaping_serverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPING_SERVERDLG_H__0F3E227A_8CB5_47BE_8841_F4EE934891BE__INCLUDED_)
