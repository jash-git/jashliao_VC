// BeckRS485ControlDlg.h : header file
//

#if !defined(AFX_BECKRS485CONTROLDLG_H__6010D42B_6B4F_4E21_BCD6_7BE4E9F87E4E__INCLUDED_)
#define AFX_BECKRS485CONTROLDLG_H__6010D42B_6B4F_4E21_BCD6_7BE4E9F87E4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RS232.h"//step 1
/////////////////////////////////////////////////////////////////////////////
// CBeckRS485ControlDlg dialog

class CBeckRS485ControlDlg : public CDialog
{
// Construction
public:
	CBeckRS485ControlDlg(CWnd* pParent = NULL);	// standard constructor
	CRS232 RS;
// Dialog Data
	//{{AFX_DATA(CBeckRS485ControlDlg)
	enum { IDD = IDD_BECKRS485CONTROL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBeckRS485ControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBeckRS485ControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenRS485();
	afx_msg void OnDestroy();
	afx_msg void OnCalibrateBed();
	afx_msg void OnMoveHeadUp();
	afx_msg void OnMoveHeadDn();
	afx_msg void OnMoveFootUp();
	afx_msg void OnMoveFootDn();
	afx_msg void OnStopMove();
	afx_msg void OnMemoryFunction();
	afx_msg void OnSetBedHeadPosition();
	afx_msg void OnSetBedFootPosition();
	afx_msg void OnHeadVibrationUp();
	afx_msg void OnHeadVibrationDn();
	afx_msg void OnFootVibrationUp();
	afx_msg void OnFootVibrationDn();
	afx_msg void OnStopVibration();
	afx_msg void OnVibrationFunction();
	afx_msg void OnSetBedHeadVibration();
	afx_msg void OnSetBedFootVibration();
	afx_msg void OnGetPosition();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BECKRS485CONTROLDLG_H__6010D42B_6B4F_4E21_BCD6_7BE4E9F87E4E__INCLUDED_)
