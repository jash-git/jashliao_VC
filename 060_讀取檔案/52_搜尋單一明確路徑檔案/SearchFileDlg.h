// SearchFileDlg.h : header file
//

#if !defined(AFX_SEARCHFILEDLG_H__2C5F83E7_66D6_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_SEARCHFILEDLG_H__2C5F83E7_66D6_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSearchFileDlg dialog

class CSearchFileDlg : public CDialog
{
// Construction
public:
	CSearchFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchFileDlg)
	enum { IDD = IDD_SEARCHFILE_DIALOG };
	CListBox	m_ctrlFilesList;
	CString	m_strDir;
	CString	m_strFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	BOOL SearchFile(CString StrFileName);
	// Generated message map functions
	//{{AFX_MSG(CSearchFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSearchfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHFILEDLG_H__2C5F83E7_66D6_11D6_8F32_00E04CE76240__INCLUDED_)
