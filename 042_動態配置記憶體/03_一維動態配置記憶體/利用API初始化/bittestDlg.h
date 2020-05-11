// bittestDlg.h : header file
//

#if !defined(AFX_BITTESTDLG_H__6FEB0E86_2902_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_BITTESTDLG_H__6FEB0E86_2902_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBittestDlg dialog

class CBittestDlg : public CDialog
{
// Construction
public:
	CBittestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBittestDlg)
	enum { IDD = IDD_BITTEST_DIALOG };
	long	m_s1;
	long	m_m1;
	long	m_s2;
	long	m_m2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBittestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBittestDlg)
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

#endif // !defined(AFX_BITTESTDLG_H__6FEB0E86_2902_11DA_B776_0040F43A9B72__INCLUDED_)
