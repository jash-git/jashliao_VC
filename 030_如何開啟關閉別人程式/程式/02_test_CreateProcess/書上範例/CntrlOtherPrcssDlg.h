// CntrlOtherPrcssDlg.h : header file
//

#if !defined(AFX_CNTRLOTHERPRCSSDLG_H__E9E5388A_6F62_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_CNTRLOTHERPRCSSDLG_H__E9E5388A_6F62_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCntrlOtherPrcssDlg dialog

class CCntrlOtherPrcssDlg : public CDialog
{
// Construction
public:
	CCntrlOtherPrcssDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCntrlOtherPrcssDlg)
	enum { IDD = IDD_CNTRLOTHERPRCSS_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCntrlOtherPrcssDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HANDLE m_hPro; 
	// Generated message map functions
	//{{AFX_MSG(CCntrlOtherPrcssDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRLOTHERPRCSSDLG_H__E9E5388A_6F62_11D6_8F32_00E04CE76240__INCLUDED_)
