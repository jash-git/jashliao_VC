// ftimebDlg.h : header file
//

#if !defined(AFX_FTIMEBDLG_H__C76C570B_2546_4D01_A7D6_EA3AE50C2E4A__INCLUDED_)
#define AFX_FTIMEBDLG_H__C76C570B_2546_4D01_A7D6_EA3AE50C2E4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFtimebDlg dialog

class CFtimebDlg : public CDialog
{
// Construction
public:
	CFtimebDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFtimebDlg)
	enum { IDD = IDD_FTIMEB_DIALOG };
	int		m_i;
	short	m_m1;
	short	m_m2;
	long	m_s1;
	long	m_s2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtimebDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFtimebDlg)
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

#endif // !defined(AFX_FTIMEBDLG_H__C76C570B_2546_4D01_A7D6_EA3AE50C2E4A__INCLUDED_)
