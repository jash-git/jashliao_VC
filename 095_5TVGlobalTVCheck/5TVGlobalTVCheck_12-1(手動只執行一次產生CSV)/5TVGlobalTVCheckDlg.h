// 5TVGlobalTVCheckDlg.h : header file
//
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_5TVGLOBALTVCHECKDLG_H__B02E6B9E_EF66_44A5_9712_BA2B3974C841__INCLUDED_)
#define AFX_5TVGLOBALTVCHECKDLG_H__B02E6B9E_EF66_44A5_9712_BA2B3974C841__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy5TVGlobalTVCheckDlg dialog
#include <afxtempl.h>//CArray Step_01 
///////////////Web_start
#include <mshtml.h>
#include <comdef.h>
#include <atlbase.h>
///////////////Web_end
class CMy5TVGlobalTVCheckDlg : public CDialog
{
// Construction
public:
	CMy5TVGlobalTVCheckDlg(CWnd* pParent = NULL);	// standard constructor
	bool UTF8File2ANSIFile(CString StrUTF8,CString StrANSI);
	bool DissolutionDataString(CString StrFileName);
	void initfunction();
	bool GetWebFile(CString theUrl, CString Filename);//http_download
	void GetXmlParameter();//step 3:Åª¨úXML
	void CompareAndAnalyzeChannel();
	void CallWebService();
	///////////////Web_start
	bool HasItem(IHTMLElementCollection *pobjAllElement,CString strName);
	void PutIEText(IHTMLElementCollection *pobjAllElement,CString strName,CString strText);
	void SubmitPage(IHTMLElementCollection *pobjAllElement,CString strName);
	void CheckItem(IHTMLElementCollection *pobjAllElement,CString strName);
	CString GetHidText(IHTMLElementCollection *pobjAllElement,CString strName);
	void SelectItemValue(IHTMLElementCollection *pobjAllElement,CString strName,long number);
	void PutIEFile(IHTMLElementCollection *pobjAllElement,CString strName,CString strText);
	///////////////Web_end
public:
	CArray <CString,CString&> m_ArrayName;//CArray Step_02
	CArray <CString,CString&> m_ArrayMMS;//CArray Step_02
	CArray <CString,CString&> m_ArrayMMSPlayTime;
	CArray <CString,CString&> m_ArrayMMSState;
	CArray <CString,CString&> m_ArrayServiceID;
	CArray <CString,CString&> m_ArrayChannelName;
	CArray <CString,CString&> m_ArrayChannelUrl;
	int m_intMMSUrlNumber;
	int m_intMMSUrlCount;
	int m_TimerCount;
	CString m_StrMMSUrl;
	CString m_StrMMSName;
	FILE *m_pfPlayState;
	bool m_blnState;
	CString m_StrWebServiceUrl;
	CString m_StrWebServiceXmlName;
// Dialog Data
	//{{AFX_DATA(CMy5TVGlobalTVCheckDlg)
	enum { IDD = IDD_MY5TVGLOBALTVCHECK_DIALOG };
	CWMPPlayer4	m_WMPlayer;
	CString	m_V1;
	CString	m_V2;
	CWebBrowser2	m_Web01;
	CString	m_v3;
	CString	m_v4;
	CString	m_v5;
	CString	m_v6;
	CString	m_v7;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy5TVGlobalTVCheckDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy5TVGlobalTVCheckDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_5TVGLOBALTVCHECKDLG_H__B02E6B9E_EF66_44A5_9712_BA2B3974C841__INCLUDED_)
