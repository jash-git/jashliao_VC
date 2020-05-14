// H264FilesCopyDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_H264FILESCOPYDLG_H__E8781DB2_3FFD_43EE_9C96_FA82B7D36637__INCLUDED_)
#define AFX_H264FILESCOPYDLG_H__E8781DB2_3FFD_43EE_9C96_FA82B7D36637__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CH264FilesCopyDlg dialog

class CH264FilesCopyDlg : public CDialog
{
// Construction
public:
	CH264FilesCopyDlg(CWnd* pParent = NULL);	// standard constructor
	static UINT ThreadFunction(LPVOID lpram);
	bool GetWebFile(CString theUrl, CString Filename);//http_download
	void Function();
	void CreateSmilCmd(CString Data,CString StrDir);
// Dialog Data
	//{{AFX_DATA(CH264FilesCopyDlg)
	enum { IDD = IDD_H264FILESCOPY_DIALOG };
	CButton	m_B1;
	CString	m_V1;
	CWebBrowser2	m_Web;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CH264FilesCopyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CH264FilesCopyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDownloadCompleteExplorer1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_H264FILESCOPYDLG_H__E8781DB2_3FFD_43EE_9C96_FA82B7D36637__INCLUDED_)
