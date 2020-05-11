// TCPDlg.h : header file
//

#if !defined(AFX_TCPDLG_H__3F034748_9BB8_43A8_B67F_96F094E8FC81__INCLUDED_)
#define AFX_TCPDLG_H__3F034748_9BB8_43A8_B67F_96F094E8FC81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//////////////////////////
#include "DataSocket.h"
#include "ListenSocket.h"
//////////////////////////
/////////////////////////////////////////////////////////////////////////////
// CTCPDlg dialog

class CTCPDlg : public CDialog
{
// Construction
public:
	CTCPDlg(CWnd* pParent = NULL);	// standard constructor
	ListenSocket ls;
// Dialog Data
	//{{AFX_DATA(CTCPDlg)
	enum { IDD = IDD_TCP_DIALOG };
	CString	m_st1;
	int		m_v1;
	float	m_v2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreate();
	afx_msg void OnListen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPDLG_H__3F034748_9BB8_43A8_B67F_96F094E8FC81__INCLUDED_)
