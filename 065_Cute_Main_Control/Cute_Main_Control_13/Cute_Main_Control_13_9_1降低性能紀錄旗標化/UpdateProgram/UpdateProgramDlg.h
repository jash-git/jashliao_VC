// UpdateProgramDlg.h : header file
//

#if !defined(AFX_UPDATEPROGRAMDLG_H__A5352503_83C7_41D9_BCCA_68DA660F2A73__INCLUDED_)
#define AFX_UPDATEPROGRAMDLG_H__A5352503_83C7_41D9_BCCA_68DA660F2A73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUpdateProgramDlg dialog

class CUpdateProgramDlg : public CDialog
{
// Construction
public:
	CUpdateProgramDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CUpdateProgramDlg)
	enum { IDD = IDD_UPDATEPROGRAM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdateProgramDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUpdateProgramDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATEPROGRAMDLG_H__A5352503_83C7_41D9_BCCA_68DA660F2A73__INCLUDED_)
