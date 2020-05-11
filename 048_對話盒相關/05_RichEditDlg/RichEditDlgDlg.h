// RichEditDlgDlg.h : header file
//

#if !defined(AFX_RICHEDITDLGDLG_H__F280BEA0_7823_4840_B376_FE51CE1024A6__INCLUDED_)
#define AFX_RICHEDITDLGDLG_H__F280BEA0_7823_4840_B376_FE51CE1024A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRichEditDlgDlg dialog

class CRichEditDlgDlg : public CDialog
{
// Construction
public:
	CRichEditDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRichEditDlgDlg)
	enum { IDD = IDD_RICHEDITDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRichEditDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRichEditDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RICHEDITDLGDLG_H__F280BEA0_7823_4840_B376_FE51CE1024A6__INCLUDED_)
