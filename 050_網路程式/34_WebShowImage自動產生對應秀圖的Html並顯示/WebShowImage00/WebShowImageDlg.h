// WebShowImageDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_WEBSHOWIMAGEDLG_H__4ABF477C_6EBE_4C52_91A0_EBFEE8168A1F__INCLUDED_)
#define AFX_WEBSHOWIMAGEDLG_H__4ABF477C_6EBE_4C52_91A0_EBFEE8168A1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWebShowImageDlg dialog

class CWebShowImageDlg : public CDialog
{
// Construction
public:
	CWebShowImageDlg(CWnd* pParent = NULL);	// standard constructor
	void BrowseDir(CString strDir);//Step 2:列出檔案清單
	CArray <CString,CString&> m_Array;//Step 2:CArray
// Dialog Data
	//{{AFX_DATA(CWebShowImageDlg)
	enum { IDD = IDD_WEBSHOWIMAGE_DIALOG };
	CWebBrowser2	m_WebControl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebShowImageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWebShowImageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBSHOWIMAGEDLG_H__4ABF477C_6EBE_4C52_91A0_EBFEE8168A1F__INCLUDED_)
