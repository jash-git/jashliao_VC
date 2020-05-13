// wmp002Dlg.h : header file
//
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
//}}AFX_INCLUDES

#if !defined(AFX_WMP002DLG_H__8F8B1C63_FC67_4C75_A3E8_6B610CE91380__INCLUDED_)
#define AFX_WMP002DLG_H__8F8B1C63_FC67_4C75_A3E8_6B610CE91380__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWmp002Dlg dialog
#include <afxtempl.h>//CArray Step_01 
class CWmp002Dlg : public CDialog
{
// Construction
public:
	CWmp002Dlg(CWnd* pParent = NULL);	// standard constructor
	CArray <CString,CString&> m_MMSArray;//CArray Step_02
// Dialog Data
	//{{AFX_DATA(CWmp002Dlg)
	enum { IDD = IDD_WMP002_DIALOG };
	CListBox	m_list;
	CWMPPlayer4	m_WMP;
	double	m_v1;
	double	m_v2;
	CString	m_v3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWmp002Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWmp002Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMP002DLG_H__8F8B1C63_FC67_4C75_A3E8_6B610CE91380__INCLUDED_)
