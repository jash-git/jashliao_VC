// test_createXMLDlg.h : header file
//

#if !defined(AFX_TEST_CREATEXMLDLG_H__748548B8_C595_4B8E_817D_7AAE0AC27B91__INCLUDED_)
#define AFX_TEST_CREATEXMLDLG_H__748548B8_C595_4B8E_817D_7AAE0AC27B91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_createXMLDlg dialog

class CTest_createXMLDlg : public CDialog
{
// Construction
public:
	CTest_createXMLDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_createXMLDlg)
	enum { IDD = IDD_TEST_CREATEXML_DIALOG };

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_createXMLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_createXMLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_CREATEXMLDLG_H__748548B8_C595_4B8E_817D_7AAE0AC27B91__INCLUDED_)
