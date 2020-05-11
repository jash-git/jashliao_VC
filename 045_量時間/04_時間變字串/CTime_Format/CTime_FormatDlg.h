// CTime_FormatDlg.h : header file
//

#if !defined(AFX_CTIME_FORMATDLG_H__4ED4077F_4C39_4DE9_B93A_A3CE188CFA98__INCLUDED_)
#define AFX_CTIME_FORMATDLG_H__4ED4077F_4C39_4DE9_B93A_A3CE188CFA98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCTime_FormatDlg dialog

class CCTime_FormatDlg : public CDialog
{
// Construction
public:
	CCTime_FormatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCTime_FormatDlg)
	enum { IDD = IDD_CTIME_FORMAT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTime_FormatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCTime_FormatDlg)
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

#endif // !defined(AFX_CTIME_FORMATDLG_H__4ED4077F_4C39_4DE9_B93A_A3CE188CFA98__INCLUDED_)
