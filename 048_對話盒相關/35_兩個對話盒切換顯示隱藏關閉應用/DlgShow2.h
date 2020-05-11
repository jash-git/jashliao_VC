#if !defined(AFX_DLGSHOW2_H__F4F4902E_1B4B_4ED6_8C12_A57A6810B92E__INCLUDED_)
#define AFX_DLGSHOW2_H__F4F4902E_1B4B_4ED6_8C12_A57A6810B92E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgShow2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgShow2 dialog

class CDlgShow2 : public CDialog
{
// Construction
public:
	CDlgShow2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgShow2)
	enum { IDD = IDD_DIALOG1 };
	double	m_v1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgShow2)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgShow2)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSHOW2_H__F4F4902E_1B4B_4ED6_8C12_A57A6810B92E__INCLUDED_)
