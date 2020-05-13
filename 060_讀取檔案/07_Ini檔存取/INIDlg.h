// INIDlg.h : header file
//

#if !defined(AFX_INIDLG_H__AB2CBEC6_1FBC_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_INIDLG_H__AB2CBEC6_1FBC_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CINIDlg dialog

class CINIDlg : public CDialog
{
// Construction
public:
	CINIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CINIDlg)
	enum { IDD = IDD_INI_DIALOG };
	CString	m_val;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CINIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CINIDlg)
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

#endif // !defined(AFX_INIDLG_H__AB2CBEC6_1FBC_11DA_B776_0040F43A9B72__INCLUDED_)
