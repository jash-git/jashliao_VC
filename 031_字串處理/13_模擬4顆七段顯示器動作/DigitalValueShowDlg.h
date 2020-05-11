// DigitalValueShowDlg.h : header file
//

#if !defined(AFX_DIGITALVALUESHOWDLG_H__37DE930B_D1CB_4512_A7C3_E60FB49A5CEB__INCLUDED_)
#define AFX_DIGITALVALUESHOWDLG_H__37DE930B_D1CB_4512_A7C3_E60FB49A5CEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDigitalValueShowDlg dialog

class CDigitalValueShowDlg : public CDialog
{
// Construction
public:
	CDigitalValueShowDlg(CWnd* pParent = NULL);	// standard constructor
	CString ChangeData(char *data,int code);
	void MoveLeft(char *data);
// Dialog Data
	//{{AFX_DATA(CDigitalValueShowDlg)
	enum { IDD = IDD_DIGITALVALUESHOW_DIALOG };
	int		m_v1;
	CString	m_str1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDigitalValueShowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDigitalValueShowDlg)
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

#endif // !defined(AFX_DIGITALVALUESHOWDLG_H__37DE930B_D1CB_4512_A7C3_E60FB49A5CEB__INCLUDED_)
