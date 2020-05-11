// DrvSrlNmbrDlg.h : header file
//

#if !defined(AFX_DRVSRLNMBRDLG_H__CBBA57E7_702B_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_DRVSRLNMBRDLG_H__CBBA57E7_702B_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDrvSrlNmbrDlg dialog

class CDrvSrlNmbrDlg : public CDialog
{
// Construction
public:
	CDrvSrlNmbrDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDrvSrlNmbrDlg)
	enum { IDD = IDD_DRVSRLNMBR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrvSrlNmbrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void FindAllDrivers();
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDrvSrlNmbrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetSrlNum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRVSRLNMBRDLG_H__CBBA57E7_702B_11D6_8F32_00E04CE76240__INCLUDED_)
