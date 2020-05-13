// Create_2003AD_UserDlg.h : header file
//

#if !defined(AFX_CREATE_2003AD_USERDLG_H__9FAC2E07_3A2A_45F5_B596_50ACE7A5247F__INCLUDED_)
#define AFX_CREATE_2003AD_USERDLG_H__9FAC2E07_3A2A_45F5_B596_50ACE7A5247F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreate_2003AD_UserDlg dialog

class CCreate_2003AD_UserDlg : public CDialog
{
// Construction
public:
	CCreate_2003AD_UserDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreate_2003AD_UserDlg)
	enum { IDD = IDD_CREATE_2003AD_USER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreate_2003AD_UserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreate_2003AD_UserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreateFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATE_2003AD_USERDLG_H__9FAC2E07_3A2A_45F5_B596_50ACE7A5247F__INCLUDED_)
