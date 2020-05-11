#if !defined(AFX_FORVIEW_H__857797CF_50A5_49E0_A840_5EE2643B754F__INCLUDED_)
#define AFX_FORVIEW_H__857797CF_50A5_49E0_A840_5EE2643B754F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// forview.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// forview form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class forview : public CFormView
{
protected:
	forview();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(forview)

// Form Data
public:
	//{{AFX_DATA(forview)
	enum { IDD = IDD_FORMVIEW };
	int		m_v1;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(forview)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~forview();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(forview)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORVIEW_H__857797CF_50A5_49E0_A840_5EE2643B754F__INCLUDED_)
