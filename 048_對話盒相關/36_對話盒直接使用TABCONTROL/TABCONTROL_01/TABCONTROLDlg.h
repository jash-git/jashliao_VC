// TABCONTROLDlg.h : header file
//

#if !defined(AFX_TABCONTROLDLG_H__27826990_989D_4530_930E_5026234C4870__INCLUDED_)
#define AFX_TABCONTROLDLG_H__27826990_989D_4530_930E_5026234C4870__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTABCONTROLDlg dialog

class CTABCONTROLDlg : public CDialog
{
// Construction
public:
	CTABCONTROLDlg(CWnd* pParent = NULL);	// standard constructor
	void showTab();
	CPropertySheet *sheet;
// Dialog Data
	//{{AFX_DATA(CTABCONTROLDlg)
	enum { IDD = IDD_TABCONTROL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTABCONTROLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTABCONTROLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABCONTROLDLG_H__27826990_989D_4530_930E_5026234C4870__INCLUDED_)
