// ProjCombDlg.h : header file
//

#if !defined(AFX_PROJCOMBDLG_H__750AF406_196E_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_PROJCOMBDLG_H__750AF406_196E_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProjCombDlg dialog

class CProjCombDlg : public CDialog
{
// Construction
public:
	CProjCombDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CProjCombDlg)
	enum { IDD = IDD_PROJCOMB_DIALOG };
	CString	m_v1;
	CString	m_v2;
	CString	m_v3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjCombDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProjCombDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnDblclkList1();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnEditupdateCombo1();
	afx_msg void OnDropdownCombo1();
	afx_msg void OnCloseupCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJCOMBDLG_H__750AF406_196E_11DA_B776_0040F43A9B72__INCLUDED_)
