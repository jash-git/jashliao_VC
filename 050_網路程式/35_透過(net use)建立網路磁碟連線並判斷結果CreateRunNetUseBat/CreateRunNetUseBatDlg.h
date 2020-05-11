// CreateRunNetUseBatDlg.h : header file
//

#if !defined(AFX_CREATERUNNETUSEBATDLG_H__CBC928BF_2DB1_46EA_BBA6_9A92D0219A20__INCLUDED_)
#define AFX_CREATERUNNETUSEBATDLG_H__CBC928BF_2DB1_46EA_BBA6_9A92D0219A20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateRunNetUseBatDlg dialog

class CCreateRunNetUseBatDlg : public CDialog
{
// Construction
public:
	CCreateRunNetUseBatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateRunNetUseBatDlg)
	enum { IDD = IDD_CREATERUNNETUSEBAT_DIALOG };
	CString	m_IP;
	CString	m_Name;
	CString	m_PWS;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateRunNetUseBatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateRunNetUseBatDlg)
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

#endif // !defined(AFX_CREATERUNNETUSEBATDLG_H__CBC928BF_2DB1_46EA_BBA6_9A92D0219A20__INCLUDED_)
