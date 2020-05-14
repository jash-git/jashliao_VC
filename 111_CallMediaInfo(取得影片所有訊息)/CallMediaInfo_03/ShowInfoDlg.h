#if !defined(AFX_SHOWINFODLG_H__082BB219_6A14_4B49_87FF_258CCFF7E0BF__INCLUDED_)
#define AFX_SHOWINFODLG_H__082BB219_6A14_4B49_87FF_258CCFF7E0BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShowInfoDlg dialog

class CShowInfoDlg : public CDialog
{
// Construction
public:
	CShowInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShowInfoDlg)
	enum { IDD = IDD_ShowInfo };
	CString	m_V1;
	CString	m_V2;
	CString	m_V3;
	CString	m_V4;
	CString	m_V5;
	CString	m_V6;
	CString	m_V7;
	CString	m_V8;
	CString	m_V9;
	CString	m_V10;
	CString	m_V11;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowInfoDlg)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowInfoDlg)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWINFODLG_H__082BB219_6A14_4B49_87FF_258CCFF7E0BF__INCLUDED_)
