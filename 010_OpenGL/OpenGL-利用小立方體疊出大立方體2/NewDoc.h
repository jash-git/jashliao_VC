// NewDoc.h : interface of the CNewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWDOC_H__8C783238_24DF_4648_A6A2_ADD441E455A3__INCLUDED_)
#define AFX_NEWDOC_H__8C783238_24DF_4648_A6A2_ADD441E455A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNewDoc : public CDocument
{
protected: // create from serialization only
	CNewDoc();
	DECLARE_DYNCREATE(CNewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWDOC_H__8C783238_24DF_4648_A6A2_ADD441E455A3__INCLUDED_)
