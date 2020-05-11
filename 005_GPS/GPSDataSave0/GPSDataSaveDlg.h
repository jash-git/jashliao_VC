// GPSDataSaveDlg.h : header file
//

#if !defined(AFX_GPSDATASAVEDLG_H__884AB9E7_638E_4A97_ACB9_629E3AFAF573__INCLUDED_)
#define AFX_GPSDATASAVEDLG_H__884AB9E7_638E_4A97_ACB9_629E3AFAF573__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGPSDataSaveDlg dialog
#include "RS232.h"
class CGPSDataSaveDlg : public CDialog
{
// Construction
public:
	CGPSDataSaveDlg(CWnd* pParent = NULL);	// standard constructor
	CRS232 RS;
	int StringRipFunction(unsigned char str[],long number);
// Dialog Data
	//{{AFX_DATA(CGPSDataSaveDlg)
	enum { IDD = IDD_GPSDATASAVE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGPSDataSaveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGPSDataSaveDlg)
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

#endif // !defined(AFX_GPSDATASAVEDLG_H__884AB9E7_638E_4A97_ACB9_629E3AFAF573__INCLUDED_)
