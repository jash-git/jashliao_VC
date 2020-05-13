// readwriteDlg.h : header file
//

#if !defined(AFX_READWRITEDLG_H__4D44608B_0141_48EE_A058_0ACC29CD3554__INCLUDED_)
#define AFX_READWRITEDLG_H__4D44608B_0141_48EE_A058_0ACC29CD3554__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReadwriteDlg dialog

class CReadwriteDlg : public CDialog
{
// Construction
public:
	CReadwriteDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReadwriteDlg)
	enum { IDD = IDD_READWRITE_DIALOG };
	CButton	m_but2;
	CButton	m_but1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadwriteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReadwriteDlg)
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

#endif // !defined(AFX_READWRITEDLG_H__4D44608B_0141_48EE_A058_0ACC29CD3554__INCLUDED_)
