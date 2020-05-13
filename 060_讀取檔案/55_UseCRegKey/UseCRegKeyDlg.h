// UseCRegKeyDlg.h : header file
//

#if !defined(AFX_USECREGKEYDLG_H__8D43F3C5_9C27_458D_A0D2_E69BBB409092__INCLUDED_)
#define AFX_USECREGKEYDLG_H__8D43F3C5_9C27_458D_A0D2_E69BBB409092__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseCRegKeyDlg dialog

class CUseCRegKeyDlg : public CDialog
{
// Construction
public:
	CUseCRegKeyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUseCRegKeyDlg)
	enum { IDD = IDD_USECREGKEY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseCRegKeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseCRegKeyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USECREGKEYDLG_H__8D43F3C5_9C27_458D_A0D2_E69BBB409092__INCLUDED_)
