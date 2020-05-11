#if !defined(AFX_TEXT2_H__59722EC0_F529_48AA_BCBE_89383949D0F3__INCLUDED_)
#define AFX_TEXT2_H__59722EC0_F529_48AA_BCBE_89383949D0F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Text2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CText2 dialog

class CText2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CText2)

// Construction
public:
	CText2();
	~CText2();

// Dialog Data
	//{{AFX_DATA(CText2)
	enum { IDD = IDD_PROPPAGE_SMALL1 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CText2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CText2)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXT2_H__59722EC0_F529_48AA_BCBE_89383949D0F3__INCLUDED_)
