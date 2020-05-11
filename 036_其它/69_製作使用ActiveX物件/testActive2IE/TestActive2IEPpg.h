#if !defined(AFX_TESTACTIVE2IEPPG_H__A9FDBAD8_DEFB_4AFE_9A2F_2FDB9BA06C08__INCLUDED_)
#define AFX_TESTACTIVE2IEPPG_H__A9FDBAD8_DEFB_4AFE_9A2F_2FDB9BA06C08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TestActive2IEPpg.h : Declaration of the CTestActive2IEPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CTestActive2IEPropPage : See TestActive2IEPpg.cpp.cpp for implementation.

class CTestActive2IEPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTestActive2IEPropPage)
	DECLARE_OLECREATE_EX(CTestActive2IEPropPage)

// Constructor
public:
	CTestActive2IEPropPage();

// Dialog Data
	//{{AFX_DATA(CTestActive2IEPropPage)
	enum { IDD = IDD_PROPPAGE_TESTACTIVE2IE };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CTestActive2IEPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTACTIVE2IEPPG_H__A9FDBAD8_DEFB_4AFE_9A2F_2FDB9BA06C08__INCLUDED)
