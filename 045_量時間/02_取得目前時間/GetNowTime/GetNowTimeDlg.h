// GetNowTimeDlg.h : header file
//

#if !defined(AFX_GETNOWTIMEDLG_H__0BD98EEC_420C_4004_B1A6_5975A129E3F6__INCLUDED_)
#define AFX_GETNOWTIMEDLG_H__0BD98EEC_420C_4004_B1A6_5975A129E3F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetNowTimeDlg dialog

class CGetNowTimeDlg : public CDialog
{
// Construction
public:
	CGetNowTimeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetNowTimeDlg)
	enum { IDD = IDD_GETNOWTIME_DIALOG };
	float	m_v1;
	float	m_v2;
	float	m_v3;
	float	m_v4;
	float	m_v5;
	float	m_v6;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetNowTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetNowTimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETNOWTIMEDLG_H__0BD98EEC_420C_4004_B1A6_5975A129E3F6__INCLUDED_)
