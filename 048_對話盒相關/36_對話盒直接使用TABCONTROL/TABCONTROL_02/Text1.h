#if !defined(AFX_TEXT1_H__DCD08998_95FD_4457_822F_74B344893151__INCLUDED_)
#define AFX_TEXT1_H__DCD08998_95FD_4457_822F_74B344893151__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Text1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CText1 dialog

class CText1 : public CPropertyPage
{
	DECLARE_DYNCREATE(CText1)

// Construction
public:
	CText1();
	~CText1();
	void show();
	CPropertySheet *sheet;

// Dialog Data
	//{{AFX_DATA(CText1)
	enum { IDD = IDD_PROPPAGE_SMALL };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CText1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CText1)
	afx_msg void OnButton1();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXT1_H__DCD08998_95FD_4457_822F_74B344893151__INCLUDED_)
