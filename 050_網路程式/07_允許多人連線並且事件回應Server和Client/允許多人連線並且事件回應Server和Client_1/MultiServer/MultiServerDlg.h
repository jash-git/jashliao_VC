// MultiServerDlg.h : header file
//

#if !defined(AFX_MULTISERVERDLG_H__2C71949F_9C4C_4344_9451_BB9C2CF0354C__INCLUDED_)
#define AFX_MULTISERVERDLG_H__2C71949F_9C4C_4344_9451_BB9C2CF0354C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiServerDlg dialog
#include "ListenSocket.h"
class CMultiServerDlg : public CDialog
{
// Construction
public:
	CMultiServerDlg(CWnd* pParent = NULL);	// standard constructor
	CListenSocket ls;
	CArray<CSocket *,CSocket *> SocketArray;
	CArray<CSocket *,CSocket *> & GetSocketArray(){return SocketArray;}
	afx_msg void GetNetData();
// Dialog Data
	//{{AFX_DATA(CMultiServerDlg)
	enum { IDD = IDD_MULTISERVER_DIALOG };
	CString	m_v1;
	CString	m_v2;
	CString	m_v3;
	CString	m_v4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiServerDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTISERVERDLG_H__2C71949F_9C4C_4344_9451_BB9C2CF0354C__INCLUDED_)
