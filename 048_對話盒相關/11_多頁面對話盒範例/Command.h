#if !defined(AFX_COMMAND_H__513B1C87_3930_4EF3_9763_D0E061F6A42C__INCLUDED_)
#define AFX_COMMAND_H__513B1C87_3930_4EF3_9763_D0E061F6A42C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Command.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommand dialog

class CCommand : public CPropertyPage
{
	DECLARE_DYNCREATE(CCommand)

// Construction
public:
	CCommand();
	~CCommand();

// Dialog Data
	//{{AFX_DATA(CCommand)
	enum { IDD = IDD_PROPPAGE_SMALL1 };
	double	m_v1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CCommand)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCommand)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMAND_H__513B1C87_3930_4EF3_9763_D0E061F6A42C__INCLUDED_)
