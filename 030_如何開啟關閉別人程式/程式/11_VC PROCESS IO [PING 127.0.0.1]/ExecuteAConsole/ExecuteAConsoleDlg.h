// ExecuteAConsoleDlg.h : header file
//

#if !defined(AFX_EXECUTEACONSOLEDLG_H__F197009F_65E7_454D_BF57_47191C135C4D__INCLUDED_)
#define AFX_EXECUTEACONSOLEDLG_H__F197009F_65E7_454D_BF57_47191C135C4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExecuteAConsoleDlg dialog

class CExecuteAConsoleDlg : public CDialog
{
// Construction
public:
	CExecuteAConsoleDlg(CWnd* pParent = NULL);	// standard constructor
	CString ExecuteExternalFile(CString csExeName, CString csArguments);
// Dialog Data
	//{{AFX_DATA(CExecuteAConsoleDlg)
	enum { IDD = IDD_EXECUTEACONSOLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExecuteAConsoleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExecuteAConsoleDlg)
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

#endif // !defined(AFX_EXECUTEACONSOLEDLG_H__F197009F_65E7_454D_BF57_47191C135C4D__INCLUDED_)
