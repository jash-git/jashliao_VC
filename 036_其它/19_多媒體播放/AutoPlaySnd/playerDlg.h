// playerDlg.h : header file
//
//{{AFX_INCLUDES()
#include "activemovie3.h"
//}}AFX_INCLUDES

#if !defined(AFX_PLAYERDLG_H__F5B21A8A_5EE9_11D7_BCB5_CEB29E77AC3D__INCLUDED_)
#define AFX_PLAYERDLG_H__F5B21A8A_5EE9_11D7_BCB5_CEB29E77AC3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPlayerDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlg dialog

class CPlayerDlg : public CDialog
{
	DECLARE_DYNAMIC(CPlayerDlg);
	friend class CPlayerDlgAutoProxy;

// Construction
public:
	CPlayerDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CPlayerDlg();

// Dialog Data
	//{{AFX_DATA(CPlayerDlg)
	enum { IDD = IDD_PLAYER_DIALOG };
	CButton	m_stop;
	CButton	m_play;
	CListBox	m_list;
	CButton	m_openfile;
	CActiveMovie3	m_activemovie;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CPlayerDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYERDLG_H__F5B21A8A_5EE9_11D7_BCB5_CEB29E77AC3D__INCLUDED_)
