// addDlg.h : header file
//

#if !defined(AFX_ADDDLG_H__CBCB221E_0B57_4DBC_8F53_24A77600FD1E__INCLUDED_)
#define AFX_ADDDLG_H__CBCB221E_0B57_4DBC_8F53_24A77600FD1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAddDlg dialog

class CAddDlg : public CDialog
{
// Construction
public:
	CAddDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAddDlg)
	enum { IDD = IDD_ADD_DIALOG };
	int		m_v1;
	int		m_v2;
	int		m_v3;
	int		m_v4;
	int		m_v5;
	int		m_v6;
	int		m_v7;
	int		m_v8;
	int		m_v9;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAddDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDLG_H__CBCB221E_0B57_4DBC_8F53_24A77600FD1E__INCLUDED_)
