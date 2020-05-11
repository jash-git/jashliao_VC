#if !defined(AFX_TEXT_H__A8046239_DB52_4459_A925_B48E0BDFA625__INCLUDED_)
#define AFX_TEXT_H__A8046239_DB52_4459_A925_B48E0BDFA625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Text.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CText dialog

class CText : public CPropertyPage
{
	DECLARE_DYNCREATE(CText)

// Construction
public:
	CText();
	~CText();

// Dialog Data
	//{{AFX_DATA(CText)
	enum { IDD = IDD_PROPPAGE_SMALL };
	double	m_v1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CText)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CText)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXT_H__A8046239_DB52_4459_A925_B48E0BDFA625__INCLUDED_)
