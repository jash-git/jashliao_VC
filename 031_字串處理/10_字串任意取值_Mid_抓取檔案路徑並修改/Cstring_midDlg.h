// Cstring_midDlg.h : header file
//

#if !defined(AFX_CSTRING_MIDDLG_H__0C7D0646_302E_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_CSTRING_MIDDLG_H__0C7D0646_302E_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCstring_midDlg dialog

class CCstring_midDlg : public CDialog
{
// Construction
public:
	CCstring_midDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCstring_midDlg)
	enum { IDD = IDD_CSTRING_MID_DIALOG };
	CString	m_v1;
	CString	m_v2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCstring_midDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCstring_midDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTRING_MIDDLG_H__0C7D0646_302E_11DA_B776_0040F43A9B72__INCLUDED_)
