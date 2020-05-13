// VC_CreateMuliteDirectoryDlg.h : header file
//

#if !defined(AFX_VC_CREATEMULITEDIRECTORYDLG_H__DC580202_F1D0_487D_A5CD_7E3EC1C8390E__INCLUDED_)
#define AFX_VC_CREATEMULITEDIRECTORYDLG_H__DC580202_F1D0_487D_A5CD_7E3EC1C8390E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVC_CreateMuliteDirectoryDlg dialog

class CVC_CreateMuliteDirectoryDlg : public CDialog
{
// Construction
public:
	CVC_CreateMuliteDirectoryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVC_CreateMuliteDirectoryDlg)
	enum { IDD = IDD_VC_CREATEMULITEDIRECTORY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVC_CreateMuliteDirectoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVC_CreateMuliteDirectoryDlg)
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

#endif // !defined(AFX_VC_CREATEMULITEDIRECTORYDLG_H__DC580202_F1D0_487D_A5CD_7E3EC1C8390E__INCLUDED_)
