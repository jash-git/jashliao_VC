// ControlHWMonitorDlg.h : header file
//

#if !defined(AFX_CONTROLHWMONITORDLG_H__50FFDFC8_9CCC_46DD_BB16_91D370F4BA0C__INCLUDED_)
#define AFX_CONTROLHWMONITORDLG_H__50FFDFC8_9CCC_46DD_BB16_91D370F4BA0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CControlHWMonitorDlg dialog

class CControlHWMonitorDlg : public CDialog
{
// Construction
public:
	CControlHWMonitorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CControlHWMonitorDlg)
	enum { IDD = IDD_CONTROLHWMONITOR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControlHWMonitorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CControlHWMonitorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreateProgram();
	afx_msg void OnCloseProgram();
	afx_msg void OnSaveData();
	afx_msg void OnSaveDatas();
	afx_msg void Onautomatic();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLHWMONITORDLG_H__50FFDFC8_9CCC_46DD_BB16_91D370F4BA0C__INCLUDED_)
