#if !defined(AFX_PPDLG_H__4FDBEA72_0B78_4CB8_883B_27317DBFE73E__INCLUDED_)
#define AFX_PPDLG_H__4FDBEA72_0B78_4CB8_883B_27317DBFE73E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PPDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPPDlg dialog

#include"TransparentImage.h"
 
class CPPDlg : public CDialog
{
// Construction
public:
	CPPDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPPDlg)
	enum { IDD = IDD_PP };
	CStatic	m_icon;
	CSliderCtrl	m_sld;
	CProgressCtrl	m_p;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CWnd m_wndParent;
	// Generated message map functions
	//{{AFX_MSG(CPPDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPDLG_H__4FDBEA72_0B78_4CB8_883B_27317DBFE73E__INCLUDED_)
