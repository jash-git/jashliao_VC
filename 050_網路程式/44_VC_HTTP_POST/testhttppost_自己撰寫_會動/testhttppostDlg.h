// testhttppostDlg.h : header file
//

#if !defined(AFX_TESTHTTPPOSTDLG_H__6843F2DE_60F4_457D_949E_C821CDE21704__INCLUDED_)
#define AFX_TESTHTTPPOSTDLG_H__6843F2DE_60F4_457D_949E_C821CDE21704__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTesthttppostDlg dialog

class CTesthttppostDlg : public CDialog
{
// Construction
public:
	CTesthttppostDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTesthttppostDlg)
	enum { IDD = IDD_TESTHTTPPOST_DIALOG };
	CString	m_StrUrl;
	CString	m_StrData;
	CString	m_StrAns;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesthttppostDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTesthttppostDlg)
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

#endif // !defined(AFX_TESTHTTPPOSTDLG_H__6843F2DE_60F4_457D_949E_C821CDE21704__INCLUDED_)
