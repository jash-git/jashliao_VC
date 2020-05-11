// HttpDownLoadFileDlg.h : header file
//

#if !defined(AFX_HTTPDOWNLOADFILEDLG_H__776A041E_77E3_47F6_9EEF_E5D23E8B679C__INCLUDED_)
#define AFX_HTTPDOWNLOADFILEDLG_H__776A041E_77E3_47F6_9EEF_E5D23E8B679C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHttpDownLoadFileDlg dialog

class CHttpDownLoadFileDlg : public CDialog
{
// Construction
public:
	CHttpDownLoadFileDlg(CWnd* pParent = NULL);	// standard constructor
	bool GetWebFile(CString theUrl, CString Filename);
// Dialog Data
	//{{AFX_DATA(CHttpDownLoadFileDlg)
	enum { IDD = IDD_HTTPDOWNLOADFILE_DIALOG };
	CString	m_URL;
	CString	m_Name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHttpDownLoadFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHttpDownLoadFileDlg)
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

#endif // !defined(AFX_HTTPDOWNLOADFILEDLG_H__776A041E_77E3_47F6_9EEF_E5D23E8B679C__INCLUDED_)
