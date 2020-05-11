// Multithread_StructDlg.h : header file
//

#if !defined(AFX_MULTITHREAD_STRUCTDLG_H__1573BCB7_FF1B_4B93_A2F8_4ED5E6F45C93__INCLUDED_)
#define AFX_MULTITHREAD_STRUCTDLG_H__1573BCB7_FF1B_4B93_A2F8_4ED5E6F45C93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultithread_StructDlg dialog

class CMultithread_StructDlg : public CDialog
{
// Construction
public:
	CMultithread_StructDlg(CWnd* pParent = NULL);	// standard constructor
	static UINT ThreadFun(LPVOID lpram);//Step 1:°õ¦æºü
// Dialog Data
	//{{AFX_DATA(CMultithread_StructDlg)
	enum { IDD = IDD_MULTITHREAD_STRUCT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultithread_StructDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultithread_StructDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD_STRUCTDLG_H__1573BCB7_FF1B_4B93_A2F8_4ED5E6F45C93__INCLUDED_)
