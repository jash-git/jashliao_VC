// VFWDlgDlg.h : header file
//

#if !defined(AFX_VFWDLGDLG_H__D56157AA_9E51_4F89_B913_9A854DF547A8__INCLUDED_)
#define AFX_VFWDLGDLG_H__D56157AA_9E51_4F89_B913_9A854DF547A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVFWDlgDlg dialog

class CVFWDlgDlg : public CDialog
{
// Construction
public:
	CVFWDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVFWDlgDlg)
	enum { IDD = IDD_VFWDLG_DIALOG };
	CStatic	m_static;
	CEdit	m_Ed1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVFWDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVFWDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VFWDLGDLG_H__D56157AA_9E51_4F89_B913_9A854DF547A8__INCLUDED_)
