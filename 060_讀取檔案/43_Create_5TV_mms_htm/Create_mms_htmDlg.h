// Create_mms_htmDlg.h : header file
//

#if !defined(AFX_CREATE_MMS_HTMDLG_H__6B9BB851_32F8_40E4_8860_BE15661D6548__INCLUDED_)
#define AFX_CREATE_MMS_HTMDLG_H__6B9BB851_32F8_40E4_8860_BE15661D6548__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreate_mms_htmDlg dialog

class CCreate_mms_htmDlg : public CDialog
{
// Construction
public:
	CCreate_mms_htmDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreate_mms_htmDlg)
	enum { IDD = IDD_CREATE_MMS_HTM_DIALOG };
	CString	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreate_mms_htmDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreate_mms_htmDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATE_MMS_HTMDLG_H__6B9BB851_32F8_40E4_8860_BE15661D6548__INCLUDED_)
