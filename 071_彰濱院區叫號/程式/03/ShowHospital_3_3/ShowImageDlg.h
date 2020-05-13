//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES
#if !defined(AFX_SHOWIMAGEDLG_H__144178D8_6829_41FF_A097_9E22BC20B7B1__INCLUDED_)
#define AFX_SHOWIMAGEDLG_H__144178D8_6829_41FF_A097_9E22BC20B7B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowImageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShowImageDlg dialog

class CShowImageDlg : public CDialog
{
// Construction
public:
	CShowImageDlg(CWnd* pParent = NULL);   // standard constructor
	long m_lngTop,m_lngLeft,m_lngWidth,m_lngHeight;//設定視窗大小位置變數
	long m_lngShowImageTime;
	long m_lngChangeImage;
	void BrowseDir(CString strDir,CString strtype);//Step 2:列出檔案清單
	CArray <CString,CString&> m_Array;//Step 2:CArray
// Dialog Data
	//{{AFX_DATA(CShowImageDlg)
	enum { IDD = IDD_DIALOG1 };
	CWebBrowser2	m_WebControl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowImageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowImageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWIMAGEDLG_H__144178D8_6829_41FF_A097_9E22BC20B7B1__INCLUDED_)
