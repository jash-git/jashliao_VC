// computDlg.h : header file
//

#if !defined(AFX_COMPUTDLG_H__C05649E6_5059_4344_B8C0_5CF7FB77E452__INCLUDED_)
#define AFX_COMPUTDLG_H__C05649E6_5059_4344_B8C0_5CF7FB77E452__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CComputDlg dialog

class CComputDlg : public CDialog
{
// Construction
public:
	CComputDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CComputDlg)
	enum { IDD = IDD_COMPUT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CComputDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPUTDLG_H__C05649E6_5059_4344_B8C0_5CF7FB77E452__INCLUDED_)
