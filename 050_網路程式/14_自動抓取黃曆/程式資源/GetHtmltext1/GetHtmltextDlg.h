// GetHtmltextDlg.h : header file
//

#if !defined(AFX_GETHTMLTEXTDLG_H__6D48DBC3_3C6E_4B61_BDEF_97116E617A11__INCLUDED_)
#define AFX_GETHTMLTEXTDLG_H__6D48DBC3_3C6E_4B61_BDEF_97116E617A11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetHtmltextDlg dialog

class CGetHtmltextDlg : public CDialog
{
// Construction
public:
	CGetHtmltextDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetHtmltextDlg)
	enum { IDD = IDD_GETHTMLTEXT_DIALOG };
	CString	m_v1;
	CString	m_v2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetHtmltextDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetHtmltextDlg)
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

#endif // !defined(AFX_GETHTMLTEXTDLG_H__6D48DBC3_3C6E_4B61_BDEF_97116E617A11__INCLUDED_)
