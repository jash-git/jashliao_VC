#if !defined(AFX_SMALL2_H__7F522B52_7098_4388_A991_0B09E63BE2B1__INCLUDED_)
#define AFX_SMALL2_H__7F522B52_7098_4388_A991_0B09E63BE2B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// small2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Csmall2 dialog

class Csmall2 : public CPropertyPage
{
	DECLARE_DYNCREATE(Csmall2)

// Construction
public:
	Csmall2();
	~Csmall2();

// Dialog Data
	//{{AFX_DATA(Csmall2)
	enum { IDD = IDD_PROPPAGE_SMALL4 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(Csmall2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(Csmall2)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMALL2_H__7F522B52_7098_4388_A991_0B09E63BE2B1__INCLUDED_)
