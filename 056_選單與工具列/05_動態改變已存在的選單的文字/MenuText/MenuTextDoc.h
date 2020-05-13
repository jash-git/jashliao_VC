// MenuTextDoc.h : interface of the CMenuTextDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENUTEXTDOC_H__697C431F_81E6_4E26_AC89_386BEECDEF1E__INCLUDED_)
#define AFX_MENUTEXTDOC_H__697C431F_81E6_4E26_AC89_386BEECDEF1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMenuTextDoc : public CDocument
{
protected: // create from serialization only
	CMenuTextDoc();
	DECLARE_DYNCREATE(CMenuTextDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuTextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMenuTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenuTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUTEXTDOC_H__697C431F_81E6_4E26_AC89_386BEECDEF1E__INCLUDED_)
