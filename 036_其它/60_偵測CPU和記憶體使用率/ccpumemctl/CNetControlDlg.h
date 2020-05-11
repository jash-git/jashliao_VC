// CNetControlDlg.h : header file
//

#if !defined(AFX_CNETCONTROLDLG_H__3DD70203_2A05_49C0_AB70_13C1DC114655__INCLUDED_)
#define AFX_CNETCONTROLDLG_H__3DD70203_2A05_49C0_AB70_13C1DC114655__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MemUsgesCtl.h"
#include "CpuUsgesCtl.h"

/////////////////////////////////////////////////////////////////////////////
// CCNetControlDlg dialog

class CCNetControlDlg : public CDialog
{
// Construction
public:
	CCNetControlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCNetControlDlg)
	enum { IDD = IDD_CNETCONTROL_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCNetControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCNetControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:	
	CMemUsgesCtl m_MyMemCtrl;
	CCpuUsgesCtl m_MyCpuCtrl;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNETCONTROLDLG_H__3DD70203_2A05_49C0_AB70_13C1DC114655__INCLUDED_)
