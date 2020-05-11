// SmallControlDlg.h : header file
//

#if !defined(AFX_SMALLCONTROLDLG_H__479FC85C_8B29_41B7_8F8D_FC5F926C9BE8__INCLUDED_)
#define AFX_SMALLCONTROLDLG_H__479FC85C_8B29_41B7_8F8D_FC5F926C9BE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSmallControlDlg dialog

class CSmallControlDlg : public CDialog
{
// Construction
public:
	CSmallControlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSmallControlDlg)
	enum { IDD = IDD_SMALLCONTROL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSmallControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSmallControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMALLCONTROLDLG_H__479FC85C_8B29_41B7_8F8D_FC5F926C9BE8__INCLUDED_)
