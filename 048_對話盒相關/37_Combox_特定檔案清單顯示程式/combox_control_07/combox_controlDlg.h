// combox_controlDlg.h : header file
//

#if !defined(AFX_COMBOX_CONTROLDLG_H__1B3183CE_18B8_4EE6_9A3D_0DD8DC8111E9__INCLUDED_)
#define AFX_COMBOX_CONTROLDLG_H__1B3183CE_18B8_4EE6_9A3D_0DD8DC8111E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCombox_controlDlg dialog
#include <afxtempl.h>//CArray Step_01 
class CCombox_controlDlg : public CDialog
{
// Construction
public:
	CCombox_controlDlg(CWnd* pParent = NULL);	// standard constructor
	CArray <CString,CString&> m_Array1;//CArray Step_02
	void BrowseDir(CString strDir);
	void ShowData(long lngNowPage);
	afx_msg void On_click0();
	afx_msg void On_click1();
	afx_msg void On_click2();
	afx_msg void On_click3();
	afx_msg void On_click4();
	afx_msg void On_click5();
	afx_msg void On_click6();
	afx_msg void On_click7();
	afx_msg void On_click8();
	afx_msg void On_click9();

// Dialog Data
	//{{AFX_DATA(CCombox_controlDlg)
	enum { IDD = IDD_COMBOX_CONTROL_DIALOG };
	CButton	m_combox8;
	CButton	m_combox7;
	CButton	m_combox6;
	CButton	m_combox4;
	CButton	m_combox5;
	CButton	m_combox3;
	CButton	m_combox2;
	CButton	m_combox1;
	long	m_pages;
	long	m_NowPage;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCombox_controlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCombox_controlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnCheck6();
	afx_msg void OnCheck7();
	afx_msg void OnCheck8();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOX_CONTROLDLG_H__1B3183CE_18B8_4EE6_9A3D_0DD8DC8111E9__INCLUDED_)
