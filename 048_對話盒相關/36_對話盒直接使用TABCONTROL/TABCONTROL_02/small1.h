#if !defined(AFX_SMALL1_H__B27F4C82_808C_4F2C_AE1E_D61871D910D0__INCLUDED_)
#define AFX_SMALL1_H__B27F4C82_808C_4F2C_AE1E_D61871D910D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// small1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Csmall1 dialog

class Csmall1 : public CPropertyPage
{
	DECLARE_DYNCREATE(Csmall1)

// Construction
public:
	Csmall1();
	~Csmall1();

// Dialog Data
	//{{AFX_DATA(Csmall1)
	enum { IDD = IDD_PROPPAGE_SMALL3 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(Csmall1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(Csmall1)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMALL1_H__B27F4C82_808C_4F2C_AE1E_D61871D910D0__INCLUDED_)
