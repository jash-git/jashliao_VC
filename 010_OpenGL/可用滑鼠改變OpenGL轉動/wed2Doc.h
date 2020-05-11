// wed2Doc.h : interface of the CWed2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WED2DOC_H__57E6996A_0F7C_11D6_A27B_002018393AA2__INCLUDED_)
#define AFX_WED2DOC_H__57E6996A_0F7C_11D6_A27B_002018393AA2__INCLUDED_

#include "model.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CWed2Doc : public CDocument
{
protected: // create from serialization only
	CWed2Doc();
	DECLARE_DYNCREATE(CWed2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWed2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	Model *model;
	void draw( void );
	virtual ~CWed2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWed2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WED2DOC_H__57E6996A_0F7C_11D6_A27B_002018393AA2__INCLUDED_)
