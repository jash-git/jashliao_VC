// GetIP2MACDlg.h : header file
//

#if !defined(AFX_GETIP2MACDLG_H__4AA3BF34_1791_4148_89FE_713F7700FDCF__INCLUDED_)
#define AFX_GETIP2MACDLG_H__4AA3BF34_1791_4148_89FE_713F7700FDCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetIP2MACDlg dialog

class CGetIP2MACDlg : public CDialog
{
// Construction
public:
	CGetIP2MACDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetIP2MACDlg)
	enum { IDD = IDD_GETIP2MAC_DIALOG };
	CString	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetIP2MACDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetIP2MACDlg)
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

#endif // !defined(AFX_GETIP2MACDLG_H__4AA3BF34_1791_4148_89FE_713F7700FDCF__INCLUDED_)
