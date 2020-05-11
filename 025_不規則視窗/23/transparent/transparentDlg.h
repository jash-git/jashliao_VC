// transparentDlg.h : header file
//

#if !defined(AFX_TRANSPARENTDLG_H__7E87BCC9_A89F_43D9_9EA5_A70EB53ED69E__INCLUDED_)
#define AFX_TRANSPARENTDLG_H__7E87BCC9_A89F_43D9_9EA5_A70EB53ED69E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTransparentDlg dialog

class CTransparentDlg : public CDialog
{
// Construction
public:
	CTransparentDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTransparentDlg)
	enum { IDD = IDD_TRANSPARENT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransparentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTransparentDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSPARENTDLG_H__7E87BCC9_A89F_43D9_9EA5_A70EB53ED69E__INCLUDED_)
