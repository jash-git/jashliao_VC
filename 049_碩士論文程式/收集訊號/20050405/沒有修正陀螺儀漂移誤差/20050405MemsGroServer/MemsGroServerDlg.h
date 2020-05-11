// MemsGroServerDlg.h : header file
//

#if !defined(AFX_MEMSGROSERVERDLG_H__36504E79_4741_45BD_94E8_51DF026509FA__INCLUDED_)
#define AFX_MEMSGROSERVERDLG_H__36504E79_4741_45BD_94E8_51DF026509FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMemsGroServerDlg dialog

class CMemsGroServerDlg : public CDialog
{
// Construction
public:
	CMemsGroServerDlg(CWnd* pParent = NULL);	// standard constructor
	CSocket m_sockSend;
// Dialog Data
	//{{AFX_DATA(CMemsGroServerDlg)
	enum { IDD = IDD_MEMSGROSERVER_DIALOG };
	CString	m_str1;
	double	m_v1;
	double	m_v2;
	double	m_v3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMemsGroServerDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMemsGroServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMSGROSERVERDLG_H__36504E79_4741_45BD_94E8_51DF026509FA__INCLUDED_)
