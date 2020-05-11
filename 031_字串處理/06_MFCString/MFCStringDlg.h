// MFCStringDlg.h : header file
//

#if !defined(AFX_MFCSTRINGDLG_H__88A0F58A_9802_4664_B930_EE886FC45D33__INCLUDED_)
#define AFX_MFCSTRINGDLG_H__88A0F58A_9802_4664_B930_EE886FC45D33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCStringDlg dialog

class CMFCStringDlg : public CDialog
{
// Construction
public:
	CMFCStringDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCStringDlg)
	enum { IDD = IDD_MFCSTRING_DIALOG };
	CString	m_str1;
	CString	m_str2;
	CString	m_str3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCStringDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCStringDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSTRINGDLG_H__88A0F58A_9802_4664_B930_EE886FC45D33__INCLUDED_)
