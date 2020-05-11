#if !defined(AFX_TESTACTIVE2IECTL_H__E97675CB_F634_474C_8941_131B8F9F2DA6__INCLUDED_)
#define AFX_TESTACTIVE2IECTL_H__E97675CB_F634_474C_8941_131B8F9F2DA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TestActive2IECtl.h : Declaration of the CTestActive2IECtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CTestActive2IECtrl : See TestActive2IECtl.cpp for implementation.

class CTestActive2IECtrl : public COleControl
{
	DECLARE_DYNCREATE(CTestActive2IECtrl)

// Constructor
public:
	CTestActive2IECtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestActive2IECtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CTestActive2IECtrl();

	DECLARE_OLECREATE_EX(CTestActive2IECtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CTestActive2IECtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CTestActive2IECtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CTestActive2IECtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CTestActive2IECtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CTestActive2IECtrl)
	afx_msg BOOL SetIP(LPCTSTR IP, LPCTSTR Mak, LPCTSTR GatWay, LPCTSTR DNS1, LPCTSTR DNS2);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CTestActive2IECtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CTestActive2IECtrl)
	dispidSetIP = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTACTIVE2IECTL_H__E97675CB_F634_474C_8941_131B8F9F2DA6__INCLUDED)
