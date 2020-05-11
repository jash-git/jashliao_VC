// SoyalRS232ReaderDlg.h : header file
//

#if !defined(AFX_SOYALRS232READERDLG_H__AE6ED4B2_1F5B_4EA4_96C8_24C77D5F8641__INCLUDED_)
#define AFX_SOYALRS232READERDLG_H__AE6ED4B2_1F5B_4EA4_96C8_24C77D5F8641__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RS232.h"//Step 1:RS-232
/////////////////////////////////////////////////////////////////////////////
// CSoyalRS232ReaderDlg dialog

class CSoyalRS232ReaderDlg : public CDialog
{
// Construction
public:
	CSoyalRS232ReaderDlg(CWnd* pParent = NULL);	// standard constructor
	CRS232 *pRS232;//Step 2:RS-232
	void GetandSetParameter();//step 3:Åª¨úXML
	float Fun16to10(CString StrInput);
// Dialog Data
	//{{AFX_DATA(CSoyalRS232ReaderDlg)
	enum { IDD = IDD_SOYALRS232READER_DIALOG };
	CString	m_v1;
	CString	m_v2;
	CString	m_v3;
	CString	m_v4;
	CString	m_v5;
	CString	m_v6;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoyalRS232ReaderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSoyalRS232ReaderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAutoRead();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOYALRS232READERDLG_H__AE6ED4B2_1F5B_4EA4_96C8_24C77D5F8641__INCLUDED_)
