// howhideDlgDlg.h : header file
//

#if !defined(AFX_HOWHIDEDLGDLG_H__6C10524D_3A70_490B_8B6C_E3718DE8642F__INCLUDED_)
#define AFX_HOWHIDEDLGDLG_H__6C10524D_3A70_490B_8B6C_E3718DE8642F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHowhideDlgDlg dialog

class CHowhideDlgDlg : public CDialog
{
// Construction
public:
	CHowhideDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHowhideDlgDlg)
	enum { IDD = IDD_HOWHIDEDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHowhideDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHowhideDlgDlg)
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

#endif // !defined(AFX_HOWHIDEDLGDLG_H__6C10524D_3A70_490B_8B6C_E3718DE8642F__INCLUDED_)
