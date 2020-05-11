// IE_COMDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_IE_COMDLG_H__F58C50BF_8F5E_4B4F_87C5_AEF9F0908174__INCLUDED_)
#define AFX_IE_COMDLG_H__F58C50BF_8F5E_4B4F_87C5_AEF9F0908174__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIE_COMDlg dialog
///////////////2_start
#include <mshtml.h>
#include <comdef.h>
#include <atlbase.h>
///////////////2_end
class CIE_COMDlg : public CDialog
{
// Construction
public:
	CIE_COMDlg(CWnd* pParent = NULL);	// standard constructor
	bool HasItem(IHTMLElementCollection *pobjAllElement,CString strName);
	void PutIEText(IHTMLElementCollection *pobjAllElement,CString strName,CString strText);
	void SubmitPage(IHTMLElementCollection *pobjAllElement,CString strName);
	void CheckItem(IHTMLElementCollection *pobjAllElement,CString strName);
	CString GetHidText(IHTMLElementCollection *pobjAllElement,CString strName);
	void SelectItemValue(IHTMLElementCollection *pobjAllElement,CString strName,long number);
	CArray <CString,CString&> m_UrlArray;
	CArray <CString,CString&> m_TitleArray;
// Dialog Data
	//{{AFX_DATA(CIE_COMDlg)
	enum { IDD = IDD_IE_COM_DIALOG };
	CWebBrowser2	m_ctrlWeb;//////1
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIE_COMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIE_COMDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDownloadCompleteExplorer1();
	afx_msg void OnTimer(UINT nIDEvent);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IE_COMDLG_H__F58C50BF_8F5E_4B4F_87C5_AEF9F0908174__INCLUDED_)
