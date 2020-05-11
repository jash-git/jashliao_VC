// Ascll2StrIntDlg.h : header file
//

#if !defined(AFX_ASCLL2STRINTDLG_H__5CBA1B73_D55D_4ACB_8F84_D4C2B581AEE4__INCLUDED_)
#define AFX_ASCLL2STRINTDLG_H__5CBA1B73_D55D_4ACB_8F84_D4C2B581AEE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAscll2StrIntDlg dialog

class CAscll2StrIntDlg : public CDialog
{
// Construction
public:
	CAscll2StrIntDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAscll2StrIntDlg)
	enum { IDD = IDD_ASCLL2STRINT_DIALOG };
	CString	m_str1;
	CString	m_str2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAscll2StrIntDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAscll2StrIntDlg)
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

#endif // !defined(AFX_ASCLL2STRINTDLG_H__5CBA1B73_D55D_4ACB_8F84_D4C2B581AEE4__INCLUDED_)
