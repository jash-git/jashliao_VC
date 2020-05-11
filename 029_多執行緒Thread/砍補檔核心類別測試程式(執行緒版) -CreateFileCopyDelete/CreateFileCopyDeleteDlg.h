// CreateFileCopyDeleteDlg.h : header file
//

#if !defined(AFX_CREATEFILECOPYDELETEDLG_H__688EF4DD_805A_4A50_A46A_712DEEDB70BA__INCLUDED_)
#define AFX_CREATEFILECOPYDELETEDLG_H__688EF4DD_805A_4A50_A46A_712DEEDB70BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateFileCopyDeleteDlg dialog
class CCreateFileCopyDeleteDlg : public CDialog
{
// Construction
public:
	CCreateFileCopyDeleteDlg(CWnd* pParent = NULL);	// standard constructor
	static UINT ThreadFun(LPVOID lpram);//Step 1:°õ¦æºü
	static UINT ThreadFun1(LPVOID lpram);//Step 2:°õ¦æºü
// Dialog Data
	//{{AFX_DATA(CCreateFileCopyDeleteDlg)
	enum { IDD = IDD_CREATEFILECOPYDELETE_DIALOG };
	CString	m_v1;
	CString	m_v2;
	long	m_v3;
	CString	m_v4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateFileCopyDeleteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateFileCopyDeleteDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEFILECOPYDELETEDLG_H__688EF4DD_805A_4A50_A46A_712DEEDB70BA__INCLUDED_)
