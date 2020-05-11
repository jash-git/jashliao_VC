// InternetFileDownLoadDlg.h : header file
//

#if !defined(AFX_INTERNETFILEDOWNLOADDLG_H__E92AED0E_E3F8_4D72_8AA1_BBE9F4B47864__INCLUDED_)
#define AFX_INTERNETFILEDOWNLOADDLG_H__E92AED0E_E3F8_4D72_8AA1_BBE9F4B47864__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CInternetFileDownLoadDlg dialog

class CInternetFileDownLoadDlg : public CDialog
{
// Construction
public:
	CInternetFileDownLoadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CInternetFileDownLoadDlg)
	enum { IDD = IDD_INTERNETFILEDOWNLOAD_DIALOG };
	CString	m_v1;
	CString	m_v2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInternetFileDownLoadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CInternetFileDownLoadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERNETFILEDOWNLOADDLG_H__E92AED0E_E3F8_4D72_8AA1_BBE9F4B47864__INCLUDED_)
