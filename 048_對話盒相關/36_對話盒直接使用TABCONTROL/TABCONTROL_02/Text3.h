#if !defined(AFX_TEXT3_H__10C738F5_CF5B_4E05_8986_06D89A89E83E__INCLUDED_)
#define AFX_TEXT3_H__10C738F5_CF5B_4E05_8986_06D89A89E83E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Text3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CText3 dialog

class CText3 : public CPropertyPage
{
	DECLARE_DYNCREATE(CText3)

// Construction
public:
	CText3();
	~CText3();

// Dialog Data
	//{{AFX_DATA(CText3)
	enum { IDD = IDD_PROPPAGE_SMALL2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CText3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CText3)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXT3_H__10C738F5_CF5B_4E05_8986_06D89A89E83E__INCLUDED_)
