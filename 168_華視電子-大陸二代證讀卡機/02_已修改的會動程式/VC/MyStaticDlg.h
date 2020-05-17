// MyStaticDlg.h : header file
//

#include "afxwin.h"
#include "IdCardDlg.h"
#include "PrCardDlg.h"
#include "afxcmn.h"
#include "SettingDlg.h"

#if !defined(AFX_MYSTATICDLG_H__E3625259_1439_4AE0_A91F_600E1E50509B__INCLUDED_)
#define AFX_MYSTATICDLG_H__E3625259_1439_4AE0_A91F_600E1E50509B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyStaticDlg dialog

class CMyStaticDlg : public CDialog
{
// Construction
public:
	CMyStaticDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyStaticDlg)
	enum { IDD = IDD_MYSTATIC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyStaticDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CTabCtrl m_tab;
	CIdCardDlg m_idCardDlg;
	CPrCardDlg m_prCardDlg;
	CSettingDlg m_settingDlg;

	//CRect rect;
	// Generated message map functions
	//{{AFX_MSG(CMyStaticDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTcnSelchangeTabCertType(NMHDR *pNMHDR, LRESULT *pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSTATICDLG_H__E3625259_1439_4AE0_A91F_600E1E50509B__INCLUDED_)
