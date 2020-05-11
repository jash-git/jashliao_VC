// ShowMACDlg.h : header file
//

#if !defined(AFX_SHOWMACDLG_H__CEBB5846_2432_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_SHOWMACDLG_H__CEBB5846_2432_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShowMACDlg dialog

class CShowMACDlg : public CDialog
{
// Construction
public:
	CShowMACDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShowMACDlg)
	enum { IDD = IDD_SHOWMAC_DIALOG };
	CButton	m_CBut1;
	CString	m_MAC;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowMACDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShowMACDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWMACDLG_H__CEBB5846_2432_11DA_B776_0040F43A9B72__INCLUDED_)
