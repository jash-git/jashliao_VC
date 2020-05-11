// CreateMulDirDlg.h : header file
//

#if !defined(AFX_CREATEMULDIRDLG_H__05857FC2_2175_47DD_ADB2_7BCD5B07A294__INCLUDED_)
#define AFX_CREATEMULDIRDLG_H__05857FC2_2175_47DD_ADB2_7BCD5B07A294__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateMulDirDlg dialog

class CCreateMulDirDlg : public CDialog
{
// Construction
public:
	CCreateMulDirDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateMulDirDlg)
	enum { IDD = IDD_CREATEMULDIR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateMulDirDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateMulDirDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEMULDIRDLG_H__05857FC2_2175_47DD_ADB2_7BCD5B07A294__INCLUDED_)
