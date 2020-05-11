// DlgMenuToolbarDlg.h : header file
//

#if !defined(AFX_DLGMENUTOOLBARDLG_H__7ECA1A82_54E7_41E0_84E2_587D47B39285__INCLUDED_)
#define AFX_DLGMENUTOOLBARDLG_H__7ECA1A82_54E7_41E0_84E2_587D47B39285__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgMenuToolbarDlg dialog

class CDlgMenuToolbarDlg : public CDialog
{
// Construction
public:
	CDlgMenuToolbarDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgMenuToolbarDlg)
	enum { IDD = IDD_DLGMENUTOOLBAR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMenuToolbarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CToolBar m_wndtoolbar;

	// Generated message map functions
	//{{AFX_MSG(CDlgMenuToolbarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAppAbout();
	afx_msg BOOL OnToolTipText(UINT, NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMENUTOOLBARDLG_H__7ECA1A82_54E7_41E0_84E2_587D47B39285__INCLUDED_)
