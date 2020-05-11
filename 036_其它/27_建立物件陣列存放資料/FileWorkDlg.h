// FileWorkDlg.h : header file
//

#if !defined(AFX_FILEWORKDLG_H__8D2000A6_2C0E_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_FILEWORKDLG_H__8D2000A6_2C0E_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Data.h"
/////////////////////////////////////////////////////////////////////////////
// CFileWorkDlg dialog

class CFileWorkDlg : public CDialog
{
// Construction
public:
	CFileWorkDlg(CWnd* pParent = NULL);	// standard constructor
	CArray <CData,CData> gArray;//4-step
	CData pData;//5-step
	void AddObject(CData &g);
// Dialog Data
	//{{AFX_DATA(CFileWorkDlg)
	enum { IDD = IDD_FILEWORK_DIALOG };
	CComboBox	m_Comb1;
	CString	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileWorkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileWorkDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEWORKDLG_H__8D2000A6_2C0E_11DA_B776_0040F43A9B72__INCLUDED_)
