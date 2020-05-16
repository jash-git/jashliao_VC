// Reverie_PC_1Dlg.h : header file
//

#if !defined(AFX_REVERIE_PC_1DLG_H__BF583EE7_4F56_4223_9E48_851F19A4F6C8__INCLUDED_)
#define AFX_REVERIE_PC_1DLG_H__BF583EE7_4F56_4223_9E48_851F19A4F6C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RS232.h"//step 1
/////////////////////////////////////////////////////////////////////////////
// CReverie_PC_1Dlg dialog

class CReverie_PC_1Dlg : public CDialog
{
// Construction
public:
	CReverie_PC_1Dlg(CWnd* pParent = NULL);	// standard constructor
	CRS232 RS;
	void OnOpenRS485();
	////////////////////////////////////////////////////////////////////
	//Jash.Liao add member function
	void InitialVariable(void);
	////////////////////////////////////////////////////////////////////
	//Jash.Liao add member variable
	TCHAR m_chrCurDrt[500];//存放目前目錄字串
	CString m_StrSettingFileName;
	int m_intCOMPort;
	////////////////////////////////////////////////////////////////////
	void ButtonEnable();
	void ButtonDisable();
// Dialog Data
	//{{AFX_DATA(CReverie_PC_1Dlg)
	enum { IDD = IDD_REVERIE_PC_1_DIALOG };
	CButton	m_ButtRightUp;
	CButton	m_ButtStandard2;
	CButton	m_ButtLeftUp;
	CButton	m_ButtFootUp;
	CButton	m_ButtStandard1;
	CButton	m_ButtHeadUp;
	CButton	m_ButtCalibrateBed;
	CButton	m_ButtAuto;
	CString	m_StrState;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReverie_PC_1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReverie_PC_1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTAuto();
	afx_msg void OnBUTCalibrateBed();
	afx_msg void OnDestroy();
	afx_msg void OnBUTHeadUp();
	afx_msg void OnBUTStandard1();
	afx_msg void OnBUTFootUp();
	afx_msg void OnBUTLeftUp();
	afx_msg void OnBUTStandard2();
	afx_msg void OnBUTRightUp();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REVERIE_PC_1DLG_H__BF583EE7_4F56_4223_9E48_851F19A4F6C8__INCLUDED_)
