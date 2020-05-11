// TestBrowseDlg.h : header file
//

#if !defined(AFX_TESTBROWSEDLG_H__903A0300_F295_413C_A11A_C78A742BA83D__INCLUDED_)
#define AFX_TESTBROWSEDLG_H__903A0300_F295_413C_A11A_C78A742BA83D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestBrowseDlg dialog

class CTestBrowseDlg : public CDialog
{
// Construction
public:
	CTestBrowseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestBrowseDlg)
	enum { IDD = IDD_TESTBROWSE_DIALOG };
	CString	m_Path;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestBrowseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestBrowseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTBROWSEDLG_H__903A0300_F295_413C_A11A_C78A742BA83D__INCLUDED_)
