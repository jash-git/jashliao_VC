// GPSGetDataDlg.h : header file
//

#if !defined(AFX_GPSGETDATADLG_H__94B498C4_6BC4_4471_A15D_7DBF7FBCEAC7__INCLUDED_)
#define AFX_GPSGETDATADLG_H__94B498C4_6BC4_4471_A15D_7DBF7FBCEAC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGPSGetDataDlg dialog
#include "RS232.h"
class CGPSGetDataDlg : public CDialog
{
// Construction
public:
	CGPSGetDataDlg(CWnd* pParent = NULL);	// standard constructor
	CRS232 RS;
	int StringRipFunction(unsigned char str[],long number);
// Dialog Data
	//{{AFX_DATA(CGPSGetDataDlg)
	enum { IDD = IDD_GPSGETDATA_DIALOG };
	CString	m_Input;
	CString	m_head;
	CString	m_time;
	CString	m_strLatitude;
	CString	m_strLongitude;
	CString	m_direction;
	int		m_DataOK;
	long	m_X1;
	long	m_Y1;
	double	m_fltRate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGPSGetDataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGPSGetDataDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GPSGETDATADLG_H__94B498C4_6BC4_4471_A15D_7DBF7FBCEAC7__INCLUDED_)
