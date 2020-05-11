// CutStringDlg.h : header file
//

#if !defined(AFX_CUTSTRINGDLG_H__5A417D08_A2FA_432E_BF73_503A5D2CB48F__INCLUDED_)
#define AFX_CUTSTRINGDLG_H__5A417D08_A2FA_432E_BF73_503A5D2CB48F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCutStringDlg dialog

class CCutStringDlg : public CDialog
{
// Construction
public:
	CCutStringDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCutStringDlg)
	enum { IDD = IDD_CUTSTRING_DIALOG };
	CString	m_Data0;
	CString	m_Data1;
	CString	m_Data2;
	CString	m_Data3;
	CString	m_Data4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCutStringDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCutStringDlg)
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

#endif // !defined(AFX_CUTSTRINGDLG_H__5A417D08_A2FA_432E_BF73_503A5D2CB48F__INCLUDED_)
