// Maping_clientDlg.h : header file
//

#if !defined(AFX_MAPING_CLIENTDLG_H__BE0405DB_D5DE_46D3_9087_D6CE5C8EBB99__INCLUDED_)
#define AFX_MAPING_CLIENTDLG_H__BE0405DB_D5DE_46D3_9087_D6CE5C8EBB99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMaping_clientDlg dialog

class CMaping_clientDlg : public CDialog
{
// Construction
public:
	CMaping_clientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMaping_clientDlg)
	enum { IDD = IDD_MAPING_CLIENT_DIALOG };
	double	m_v1;
	double	m_v2;
	double	m_v3;
	double	m_v4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMaping_clientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMaping_clientDlg)
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

#endif // !defined(AFX_MAPING_CLIENTDLG_H__BE0405DB_D5DE_46D3_9087_D6CE5C8EBB99__INCLUDED_)
