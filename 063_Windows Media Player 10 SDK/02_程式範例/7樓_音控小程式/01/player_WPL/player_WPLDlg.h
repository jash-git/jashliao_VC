// player_WPLDlg.h : header file
//
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
//}}AFX_INCLUDES

#if !defined(AFX_PLAYER_WPLDLG_H__13A73A74_9A3D_48A8_8FA5_EEAC09397C38__INCLUDED_)
#define AFX_PLAYER_WPLDLG_H__13A73A74_9A3D_48A8_8FA5_EEAC09397C38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPlayer_WPLDlg dialog

class CPlayer_WPLDlg : public CDialog
{
// Construction
public:
	CPlayer_WPLDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPlayer_WPLDlg)
	enum { IDD = IDD_PLAYER_WPL_DIALOG };
	CButton	m_BUT4;
	CButton	m_BUT3;
	CButton	m_BUT2;
	CButton	m_BUT1;
	CWMPPlayer4	m_player;
	BOOL	m_SW1;
	BOOL	m_SW2;
	BOOL	m_SW3;
	BOOL	m_SW4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayer_WPLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	CString StrWPL01,StrWPL02,StrWPL03,StrWPL04;
	CString SelectFile(int v);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPlayer_WPLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSw1();
	afx_msg void OnSw2();
	afx_msg void OnSw3();
	afx_msg void OnSw4();
	afx_msg void OnBut1();
	afx_msg void OnBut2();
	afx_msg void OnBut3();
	afx_msg void OnBut4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYER_WPLDLG_H__13A73A74_9A3D_48A8_8FA5_EEAC09397C38__INCLUDED_)
