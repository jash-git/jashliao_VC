// testDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_TESTDLG_H__848B760C_917B_4AB4_85DD_74AA441729A3__INCLUDED_)
#define AFX_TESTDLG_H__848B760C_917B_4AB4_85DD_74AA441729A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog
#include <MSHTML.H>//modify by jash
class CTestDlg : public CDialog
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor
	~CTestDlg();
	void	InvokeFunc();//modify by jash
	void	InvokeFuncWithParams(const CString& strParam1, int iParam2);//modify by jash
	void	InvokeFuncAdd(int iParam1, int iParam2);//modify by jash
	void	ShowModalDlg(const CString& strCaption, const CRect& rcPos);//modify by jash
	void	ShowModalLessDlg(const CString& strCaption, const CRect& rcPos);//modify by jash
	IHTMLDocument2*		m_pIHTMLDoc;//modify by jash
// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_TEST_DIALOG };
	CWebBrowser2	m_wndWeb;//modify by jash
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT FAR* URL);//modify by jash
	afx_msg void OnClose();//modify by jash
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__848B760C_917B_4AB4_85DD_74AA441729A3__INCLUDED_)
