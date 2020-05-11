// Disable_ESCDlg.h : header file
//

#if !defined(AFX_DISABLE_ESCDLG_H__932800B7_0E68_49D5_8E5C_062A3FCE9D49__INCLUDED_)
#define AFX_DISABLE_ESCDLG_H__932800B7_0E68_49D5_8E5C_062A3FCE9D49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDisable_ESCDlg dialog

class CDisable_ESCDlg : public CDialog
{
// Construction
public:
	CDisable_ESCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDisable_ESCDlg)
	enum { IDD = IDD_DISABLE_ESC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisable_ESCDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDisable_ESCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISABLE_ESCDLG_H__932800B7_0E68_49D5_8E5C_062A3FCE9D49__INCLUDED_)
