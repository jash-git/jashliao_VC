// dlltestDlg.h : header file
//

#if !defined(AFX_DLLTESTDLG_H__5295DBCC_B0AB_4F44_AC00_DF556CB59044__INCLUDED_)
#define AFX_DLLTESTDLG_H__5295DBCC_B0AB_4F44_AC00_DF556CB59044__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlltestDlg dialog

class CDlltestDlg : public CDialog
{
// Construction
public:
	CDlltestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlltestDlg)
	enum { IDD = IDD_DLLTEST_DIALOG };
	int		m_a;
	int		m_c;
	int		m_r;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlltestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlltestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLLTESTDLG_H__5295DBCC_B0AB_4F44_AC00_DF556CB59044__INCLUDED_)
