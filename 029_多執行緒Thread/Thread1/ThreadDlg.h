// ThreadDlg.h : header file
//

#if !defined(AFX_THREADDLG_H__52DEE830_AE5B_44B8_9D17_B712BA552A3F__INCLUDED_)
#define AFX_THREADDLG_H__52DEE830_AE5B_44B8_9D17_B712BA552A3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadDlg dialog

class CThreadDlg : public CDialog
{
// Construction
public:
	CThreadDlg(CWnd* pParent = NULL);	// standard constructor
	afx_msg void OnRunThread();
// Dialog Data
	//{{AFX_DATA(CThreadDlg)
	enum { IDD = IDD_THREAD_DIALOG };
	int		m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreateThread();
	//afx_msg void OnRunThread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADDLG_H__52DEE830_AE5B_44B8_9D17_B712BA552A3F__INCLUDED_)
