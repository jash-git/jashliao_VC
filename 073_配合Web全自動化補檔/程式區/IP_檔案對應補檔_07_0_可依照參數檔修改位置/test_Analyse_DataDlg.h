// test_Analyse_DataDlg.h : header file
//

#if !defined(AFX_TEST_ANALYSE_DATADLG_H__281C76C6_DFA5_4C70_B59E_CF9D1DA3CB74__INCLUDED_)
#define AFX_TEST_ANALYSE_DATADLG_H__281C76C6_DFA5_4C70_B59E_CF9D1DA3CB74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_Analyse_DataDlg dialog

class CTest_Analyse_DataDlg : public CDialog
{
// Construction
public:
	CTest_Analyse_DataDlg(CWnd* pParent = NULL);	// standard constructor
	CString m_StrNetWorkDir;
	void CreateNetWorkPath();
	bool MountNetWorkDir();
	bool SearchFile(CString strDir,CString strFile);
	void CreatInfoFileHead();
	//////////////////////////////////////////////////////SQL_Step 2_Start
	CDatabase *m_DB;
	CRecordset *m_RS;
	//////////////////////////////////////////////////////SQL_Step 2_End
	void ReadMySQLData();//SQL_Step 3
// Dialog Data
	//{{AFX_DATA(CTest_Analyse_DataDlg)
	enum { IDD = IDD_TEST_ANALYSE_DATA_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Analyse_DataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_Analyse_DataDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg LRESULT onShowTask(WPARAM wParam,LPARAM lParam); //icon_Step 3
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_ANALYSE_DATADLG_H__281C76C6_DFA5_4C70_B59E_CF9D1DA3CB74__INCLUDED_)
