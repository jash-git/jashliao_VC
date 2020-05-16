// BeckPlayerDlg.h : header file
//
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
//}}AFX_INCLUDES

#if !defined(AFX_BECKPLAYERDLG_H__FF4152DA_F197_455C_BAB4_9A0064974ACC__INCLUDED_)
#define AFX_BECKPLAYERDLG_H__FF4152DA_F197_455C_BAB4_9A0064974ACC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RS232.h"
/////////////////////////////////////////////////////////////////////////////
// CBeckPlayerDlg dialog

class CBeckPlayerDlg : public CDialog
{
// Construction
public:
	CBeckPlayerDlg(CWnd* pParent = NULL);	// standard constructor
	CRS232 RS;
	void StepControl00();
	void StepControl01();
	void StepControl02();
	void StepControl03();
	void StepControl04();
	void StepControl05();
	void StepControl06();
	void StepControl07();
	void StepControl08();
	void StepControl09();
	void StepControl10();
	void StepControl11();
	void StepControl12();
	void StepControl13();
	void StepControl14();
	void StepControl15();
	void InitRS485andBed();
// Dialog Data
	//{{AFX_DATA(CBeckPlayerDlg)
	enum { IDD = IDD_BECKPLAYER_DIALOG };
	CWMPPlayer4	m_Player;
	CString	m_V1;
	CString	m_V2;
	CString	m_V3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBeckPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBeckPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BECKPLAYERDLG_H__FF4152DA_F197_455C_BAB4_9A0064974ACC__INCLUDED_)
