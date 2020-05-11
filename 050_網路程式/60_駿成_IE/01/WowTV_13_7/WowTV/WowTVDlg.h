// WowTVDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_WOWTVDLG_H__40D9C5A3_EE5B_4B50_B11A_B1D2E8454754__INCLUDED_)
#define AFX_WOWTVDLG_H__40D9C5A3_EE5B_4B50_B11A_B1D2E8454754__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWowTVDlg dialog
//////////////////////
#include <mshtml.h>
#include <comdef.h>
#include <atlbase.h>
/////////////////////
class CWowTVDlg : public CDialog
{
// Construction
public:
	CWowTVDlg(CWnd* pParent = NULL);	// standard constructor
	void GetandSetParameter();//step 3:讀取XML
	void GetMac();//抓網卡號碼
	void GetNowTime();//取得目前時間
	void GetSrlNum();//取得硬碟號碼
	void DisDriver();//判斷磁碟機代號
	void Encrypt();//做XOR加密
	void Decrypt();//做XOR解密
	void Base64Encoded();//做Base64加密
	void Base64Decoded();//做Base64解密
	BOOL CheckInternet(LPCTSTR URL);//判斷網路是否正常
	BOOL CheckHW();//確認檔案是否存在
	////////////////////////////////////////////////////////
	bool HasItem(IHTMLElementCollection *pobjAllElement,CString strName);
	void PutIEText(IHTMLElementCollection *pobjAllElement,CString strName,CString strText);
	void SubmitPage(IHTMLElementCollection *pobjAllElement,CString strName);
	void CheckItem(IHTMLElementCollection *pobjAllElement,CString strName);
	CString GetHidText(IHTMLElementCollection *pobjAllElement,CString strName);
	void SelectItemValue(IHTMLElementCollection *pobjAllElement,CString strName,long number);
	////////////////////////////////////////////////////////////////////////////////////////
	afx_msg void On_click0();//HOOK回應事件
// Dialog Data
	//{{AFX_DATA(CWowTVDlg)
	enum { IDD = IDD_WOWTV_DIALOG };
	CWebBrowser2	m_Web;
	CWebBrowser2	m_Web2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWowTVDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWowTVDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnNavigateErrorExplorer1(LPDISPATCH pDisp, VARIANT FAR* URL, VARIANT FAR* Frame, VARIANT FAR* StatusCode, BOOL FAR* Cancel);
	afx_msg void OnNavigateComplete2Explorer1(LPDISPATCH pDisp, VARIANT FAR* URL);
	afx_msg void OnDownloadCompleteExplorer1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDownloadCompleteExplorer2();
	virtual void OnOK();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WOWTVDLG_H__40D9C5A3_EE5B_4B50_B11A_B1D2E8454754__INCLUDED_)
