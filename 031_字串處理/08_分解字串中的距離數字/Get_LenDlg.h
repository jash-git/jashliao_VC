// Get_LenDlg.h : header file
//

#if !defined(AFX_GET_LENDLG_H__64B1E89C_EC6E_4035_8138_5CEE2556FD53__INCLUDED_)
#define AFX_GET_LENDLG_H__64B1E89C_EC6E_4035_8138_5CEE2556FD53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGet_LenDlg dialog

class CGet_LenDlg : public CDialog
{
// Construction
public:
	CGet_LenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGet_LenDlg)
	enum { IDD = IDD_GET_LEN_DIALOG };
	CString	m_v1;
	long	m_v2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGet_LenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGet_LenDlg)
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

#endif // !defined(AFX_GET_LENDLG_H__64B1E89C_EC6E_4035_8138_5CEE2556FD53__INCLUDED_)
