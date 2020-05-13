// ChekMediaFileDlg.h : header file
//

#if !defined(AFX_CHEKMEDIAFILEDLG_H__3F44F2FE_9603_44DC_95F5_D1DE20CE1957__INCLUDED_)
#define AFX_CHEKMEDIAFILEDLG_H__3F44F2FE_9603_44DC_95F5_D1DE20CE1957__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChekMediaFileDlg dialog

class CChekMediaFileDlg : public CDialog
{
// Construction
public:
	CChekMediaFileDlg(CWnd* pParent = NULL);	// standard constructor
	bool GetWebFile(CString theUrl, CString Filename);//http_download
	void Function();
	static UINT ThreadFunction(LPVOID lpram);
// Dialog Data
	//{{AFX_DATA(CChekMediaFileDlg)
	enum { IDD = IDD_CHEKMEDIAFILE_DIALOG };
	CButton	m_But01;
	CString	m_StrID;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChekMediaFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChekMediaFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHEKMEDIAFILEDLG_H__3F44F2FE_9603_44DC_95F5_D1DE20CE1957__INCLUDED_)
