// test_CopyFile_APIDlg.h : header file
//

#if !defined(AFX_TEST_COPYFILE_APIDLG_H__277595A2_6E5B_4991_A67B_B7B831903976__INCLUDED_)
#define AFX_TEST_COPYFILE_APIDLG_H__277595A2_6E5B_4991_A67B_B7B831903976__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_CopyFile_APIDlg dialog

class CTest_CopyFile_APIDlg : public CDialog
{
// Construction
public:
	CTest_CopyFile_APIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_CopyFile_APIDlg)
	enum { IDD = IDD_TEST_COPYFILE_API_DIALOG };
	CString	m_strSrcFile;
	CString	m_strDstFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_CopyFile_APIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_CopyFile_APIDlg)
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

#endif // !defined(AFX_TEST_COPYFILE_APIDLG_H__277595A2_6E5B_4991_A67B_B7B831903976__INCLUDED_)
