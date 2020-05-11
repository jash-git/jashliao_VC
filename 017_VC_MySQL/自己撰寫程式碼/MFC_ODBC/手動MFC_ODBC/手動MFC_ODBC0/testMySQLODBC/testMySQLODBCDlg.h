// testMySQLODBCDlg.h : header file
//

#if !defined(AFX_TESTMYSQLODBCDLG_H__B283B8EB_CB4C_4FF6_8365_92191FA0E051__INCLUDED_)
#define AFX_TESTMYSQLODBCDLG_H__B283B8EB_CB4C_4FF6_8365_92191FA0E051__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestMySQLODBCDlg dialog

class CTestMySQLODBCDlg : public CDialog
{
// Construction
public:
	CTestMySQLODBCDlg(CWnd* pParent = NULL);	// standard constructor
//////////////////////////////////////////////////////第2步Start
	CDatabase *m_DB;
	CRecordset *m_RS;
//////////////////////////////////////////////////////第2步end
// Dialog Data
	//{{AFX_DATA(CTestMySQLODBCDlg)
	enum { IDD = IDD_TESTMYSQLODBC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestMySQLODBCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestMySQLODBCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton4();
	afx_msg void OnButton3();
	afx_msg void OnButton5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTMYSQLODBCDLG_H__B283B8EB_CB4C_4FF6_8365_92191FA0E051__INCLUDED_)
