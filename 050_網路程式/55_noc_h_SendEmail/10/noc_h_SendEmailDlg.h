// noc_h_SendEmailDlg.h : header file
//

#if !defined(AFX_NOC_H_SENDEMAILDLG_H__D3E69F93_17FF_40D7_8144_02E244D704FC__INCLUDED_)
#define AFX_NOC_H_SENDEMAILDLG_H__D3E69F93_17FF_40D7_8144_02E244D704FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNoc_h_SendEmailDlg dialog
struct UI_data
{
	int index;
	CString StrShowText;
	CString StrFileName;
	bool blnMesg;
};
class CNoc_h_SendEmailDlg : public CDialog
{
// Construction
public:
	CNoc_h_SendEmailDlg(CWnd* pParent = NULL);	// standard constructor
	void GetParameter();
	void GetUIText();
	struct UI_data m_UI_data[9];
	CString	m_username;
	CString	m_password;
	CString	m_smtpserver;
// Dialog Data
	//{{AFX_DATA(CNoc_h_SendEmailDlg)
	enum { IDD = IDD_NOC_H_SENDEMAIL_DIALOG };
	CButton	m_Open;
	CStatic	m_BMP;
	CButton	m_Clear;
	CButton	m_SM;
	CButton	m_E09;
	CButton	m_E08;
	CButton	m_E07;
	CButton	m_E06;
	CButton	m_E05;
	CButton	m_E04;
	CButton	m_E03;
	CButton	m_E02;
	CButton	m_E01;
	CString	m_Straddress;
	CString	m_Strbody;
	CString	m_Strtitle;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoc_h_SendEmailDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNoc_h_SendEmailDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTSendMail();
	afx_msg void OnBUTEmail1();
	afx_msg void OnBUTEmail2();
	afx_msg void OnBUTEmail3();
	afx_msg void OnBUTEmail4();
	afx_msg void OnBUTEmail5();
	afx_msg void OnBUTEmail6();
	afx_msg void OnBUTEmail7();
	afx_msg void OnBUTEmail8();
	afx_msg void OnBUTEmail9();
	afx_msg void OnBUTClear();
	afx_msg void OnBUTOpen();
	afx_msg void OnBUTClearALL();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOC_H_SENDEMAILDLG_H__D3E69F93_17FF_40D7_8144_02E244D704FC__INCLUDED_)
