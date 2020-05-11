// TopShowDlgDlg.h : header file
//

#if !defined(AFX_TOPSHOWDLGDLG_H__88A70086_239B_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_TOPSHOWDLGDLG_H__88A70086_239B_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTopShowDlgDlg dialog

class CTopShowDlgDlg : public CDialog
{
// Construction
public:
	CTopShowDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTopShowDlgDlg)
	enum { IDD = IDD_TOPSHOWDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTopShowDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTopShowDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOPSHOWDLGDLG_H__88A70086_239B_11DA_B776_0040F43A9B72__INCLUDED_)
