// DlgTableDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mshflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_DLGTABLEDLG_H__5AB23C18_EF5F_41A2_A7E1_FF63D63C36F2__INCLUDED_)
#define AFX_DLGTABLEDLG_H__5AB23C18_EF5F_41A2_A7E1_FF63D63C36F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgTableDlg dialog

class CDlgTableDlg : public CDialog
{
// Construction
public:
	CDlgTableDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgTableDlg)
	enum { IDD = IDD_DLGTABLE_DIALOG };
	CMSHFlexGrid	m_MSHFlexGrid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgTableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgTableDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTABLEDLG_H__5AB23C18_EF5F_41A2_A7E1_FF63D63C36F2__INCLUDED_)
