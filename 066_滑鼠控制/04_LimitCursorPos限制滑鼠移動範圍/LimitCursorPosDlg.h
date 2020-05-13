// LimitCursorPosDlg.h : header file
//

#if !defined(AFX_LIMITCURSORPOSDLG_H__17604209_8AE0_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_LIMITCURSORPOSDLG_H__17604209_8AE0_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLimitCursorPosDlg dialog

class CLimitCursorPosDlg : public CDialog
{
// Construction
public:
	CLimitCursorPosDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLimitCursorPosDlg)
	enum { IDD = IDD_LIMITCURSORPOS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLimitCursorPosDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLimitCursorPosDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClipcursor();
	afx_msg void OnReleaseclip();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIMITCURSORPOSDLG_H__17604209_8AE0_11D6_8F32_00E04CE76240__INCLUDED_)
