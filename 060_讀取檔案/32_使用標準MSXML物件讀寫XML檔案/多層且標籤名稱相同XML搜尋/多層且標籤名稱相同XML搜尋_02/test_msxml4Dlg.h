// test_msxml4Dlg.h : header file
//

#if !defined(AFX_TEST_MSXML4DLG_H__DAC1E188_1002_4949_9CAC_EAE69403774C__INCLUDED_)
#define AFX_TEST_MSXML4DLG_H__DAC1E188_1002_4949_9CAC_EAE69403774C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_msxml4Dlg dialog

class CTest_msxml4Dlg : public CDialog
{
// Construction
public:
	CTest_msxml4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_msxml4Dlg)
	enum { IDD = IDD_TEST_MSXML4_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_msxml4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_msxml4Dlg)
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

#endif // !defined(AFX_TEST_MSXML4DLG_H__DAC1E188_1002_4949_9CAC_EAE69403774C__INCLUDED_)
