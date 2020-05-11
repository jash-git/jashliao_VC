// MFCControlIEDlg.h : header file
//

#if !defined(AFX_MFCCONTROLIEDLG_H__0E964FEA_4417_49A6_8646_041BE559ED13__INCLUDED_)
#define AFX_MFCCONTROLIEDLG_H__0E964FEA_4417_49A6_8646_041BE559ED13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCControlIEDlg dialog

class CMFCControlIEDlg : public CDialog
{
// Construction
public:
	CMFCControlIEDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCControlIEDlg)
	enum { IDD = IDD_MFCCONTROLIE_DIALOG };
	CButton	m_CBut1;
	int		m_hr;
	int		m_min;
	long	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCControlIEDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCControlIEDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCCONTROLIEDLG_H__0E964FEA_4417_49A6_8646_041BE559ED13__INCLUDED_)
