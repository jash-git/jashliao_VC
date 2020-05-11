// test01Dlg.h : header file
//

#if !defined(AFX_TEST01DLG_H__593108CB_3A59_4800_8A9D_35B4DEBD5560__INCLUDED_)
#define AFX_TEST01DLG_H__593108CB_3A59_4800_8A9D_35B4DEBD5560__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest01Dlg dialog

class CTest01Dlg : public CDialog
{
// Construction
public:
	CTest01Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest01Dlg)
	enum { IDD = IDD_TEST01_DIALOG };
	CString	m_V1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest01Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest01Dlg)
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

#endif // !defined(AFX_TEST01DLG_H__593108CB_3A59_4800_8A9D_35B4DEBD5560__INCLUDED_)
