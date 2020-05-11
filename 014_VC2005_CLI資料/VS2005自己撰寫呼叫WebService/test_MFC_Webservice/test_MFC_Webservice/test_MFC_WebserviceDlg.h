// test_MFC_WebserviceDlg.h : header file
//

#pragma once


// Ctest_MFC_WebserviceDlg dialog
class Ctest_MFC_WebserviceDlg : public CDialog
{
// Construction
public:
	Ctest_MFC_WebserviceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TEST_MFC_WEBSERVICE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	CString m_value;
};
