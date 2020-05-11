// DAQ2006testDlg.h : header file
//

#if !defined(AFX_DAQ2006TESTDLG_H__960CA757_380F_48D6_93EC_3F6CDB20F276__INCLUDED_)
#define AFX_DAQ2006TESTDLG_H__960CA757_380F_48D6_93EC_3F6CDB20F276__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDAQ2006testDlg dialog

class CDAQ2006testDlg : public CDialog
{
// Construction
public:
	CDAQ2006testDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDAQ2006testDlg)
	enum { IDD = IDD_DAQ2006TEST_DIALOG };
	int		m_v0;
	int		m_v1;
	int		m_v2;
	int		m_v3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDAQ2006testDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDAQ2006testDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenCard();
	afx_msg void OnReadData();
	afx_msg void OnCloseCard();
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStartTimer();
	afx_msg void OnEndTimer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAQ2006TESTDLG_H__960CA757_380F_48D6_93EC_3F6CDB20F276__INCLUDED_)
