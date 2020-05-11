// testGetSystemMetricsDlg.h : header file
//

#if !defined(AFX_TESTGETSYSTEMMETRICSDLG_H__E291896A_5BB1_4D5D_B08A_3980911E78D2__INCLUDED_)
#define AFX_TESTGETSYSTEMMETRICSDLG_H__E291896A_5BB1_4D5D_B08A_3980911E78D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestGetSystemMetricsDlg dialog

class CTestGetSystemMetricsDlg : public CDialog
{
// Construction
public:
	CTestGetSystemMetricsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestGetSystemMetricsDlg)
	enum { IDD = IDD_TESTGETSYSTEMMETRICS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestGetSystemMetricsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestGetSystemMetricsDlg)
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

#endif // !defined(AFX_TESTGETSYSTEMMETRICSDLG_H__E291896A_5BB1_4D5D_B08A_3980911E78D2__INCLUDED_)
