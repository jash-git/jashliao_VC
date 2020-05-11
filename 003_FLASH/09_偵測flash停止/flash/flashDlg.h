// flashDlg.h : header file
//
//{{AFX_INCLUDES()
#include "shockwaveflash.h"
//}}AFX_INCLUDES

#if !defined(AFX_FLASHDLG_H__F1F9E62A_4AD1_406C_8B3D_12A21C5B252A__INCLUDED_)
#define AFX_FLASHDLG_H__F1F9E62A_4AD1_406C_8B3D_12A21C5B252A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFlashDlg dialog

class CFlashDlg : public CDialog
{
// Construction
public:
	CFlashDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFlashDlg)
	enum { IDD = IDD_FLASH_DIALOG };
	CShockwaveFlash	m_FlashPlayer;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlashDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFlashDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLASHDLG_H__F1F9E62A_4AD1_406C_8B3D_12A21C5B252A__INCLUDED_)
