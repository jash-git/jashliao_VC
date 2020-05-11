// timer1Dlg.h : header file
//

#if !defined(AFX_TIMER1DLG_H__28FC7E55_BEDD_4ED3_91FE_66F8BE899AFB__INCLUDED_)
#define AFX_TIMER1DLG_H__28FC7E55_BEDD_4ED3_91FE_66F8BE899AFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTimer1Dlg dialog

class CTimer1Dlg : public CDialog
{
// Construction
public:
	CTimer1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTimer1Dlg)
	enum { IDD = IDD_TIMER1_DIALOG };
	int		m_a;
	int		m_b;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimer1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimer1Dlg)
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

#endif // !defined(AFX_TIMER1DLG_H__28FC7E55_BEDD_4ED3_91FE_66F8BE899AFB__INCLUDED_)
