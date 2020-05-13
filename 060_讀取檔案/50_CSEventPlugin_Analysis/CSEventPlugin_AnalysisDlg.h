// CSEventPlugin_AnalysisDlg.h : header file
//

#if !defined(AFX_CSEVENTPLUGIN_ANALYSISDLG_H__3482847F_4AAF_4E70_85F5_0B58AB3ADDD2__INCLUDED_)
#define AFX_CSEVENTPLUGIN_ANALYSISDLG_H__3482847F_4AAF_4E70_85F5_0B58AB3ADDD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCSEventPlugin_AnalysisDlg dialog

class CCSEventPlugin_AnalysisDlg : public CDialog
{
// Construction
public:
	CCSEventPlugin_AnalysisDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCSEventPlugin_AnalysisDlg)
	enum { IDD = IDD_CSEVENTPLUGIN_ANALYSIS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSEventPlugin_AnalysisDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCSEventPlugin_AnalysisDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTRun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSEVENTPLUGIN_ANALYSISDLG_H__3482847F_4AAF_4E70_85F5_0B58AB3ADDD2__INCLUDED_)
