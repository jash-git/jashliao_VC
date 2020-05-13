// AnalysisPluginDlg.h : header file
//

#if !defined(AFX_ANALYSISPLUGINDLG_H__416457F0_213B_455C_9EDA_B22918F7CC20__INCLUDED_)
#define AFX_ANALYSISPLUGINDLG_H__416457F0_213B_455C_9EDA_B22918F7CC20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAnalysisPluginDlg dialog

class CAnalysisPluginDlg : public CDialog
{
// Construction
public:
	CAnalysisPluginDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAnalysisPluginDlg)
	enum { IDD = IDD_ANALYSISPLUGIN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalysisPluginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAnalysisPluginDlg)
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

#endif // !defined(AFX_ANALYSISPLUGINDLG_H__416457F0_213B_455C_9EDA_B22918F7CC20__INCLUDED_)
