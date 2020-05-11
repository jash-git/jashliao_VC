// FormatDriveSampleDlg.h : header file
//

#if !defined(AFX_FORMATDRIVESAMPLEDLG_H__E76E2C06_6516_4019_9F11_0FA7D74264C5__INCLUDED_)
#define AFX_FORMATDRIVESAMPLEDLG_H__E76E2C06_6516_4019_9F11_0FA7D74264C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFormatDriveSampleDlg dialog

class CFormatDriveSampleDlg : public CDialog
{
// Construction
public:
	CFormatDriveSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFormatDriveSampleDlg)
	enum { IDD = IDD_FORMAT_DISK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormatDriveSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	BOOL bQuickFormat;
	CString m_vollab;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFormatDriveSampleDlg)
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

#endif // !defined(AFX_FORMATDRIVESAMPLEDLG_H__E76E2C06_6516_4019_9F11_0FA7D74264C5__INCLUDED_)
