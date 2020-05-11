// SetValueDlg.h : header file
//

#if !defined(AFX_SETVALUEDLG_H__DDED5A66_AD3E_4681_9777_90641B14D0F6__INCLUDED_)
#define AFX_SETVALUEDLG_H__DDED5A66_AD3E_4681_9777_90641B14D0F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetValueDlg dialog

class CSetValueDlg : public CDialog
{
// Construction
public:
	CSetValueDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSetValueDlg)
	enum { IDD = IDD_SETVALUE_DIALOG };
	long	m_W;
	long	m_H;
	double	m_v3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetValueDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSetValueDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETVALUEDLG_H__DDED5A66_AD3E_4681_9777_90641B14D0F6__INCLUDED_)
