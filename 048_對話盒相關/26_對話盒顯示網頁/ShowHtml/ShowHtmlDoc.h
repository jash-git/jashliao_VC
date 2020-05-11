// ShowHtmlDoc.h : interface of the CShowHtmlDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWHTMLDOC_H__6866564B_7E11_11D7_886E_8A3E70C5F33E__INCLUDED_)
#define AFX_SHOWHTMLDOC_H__6866564B_7E11_11D7_886E_8A3E70C5F33E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowHtmlDoc : public CDocument
{
protected: // create from serialization only
	CShowHtmlDoc();
	DECLARE_DYNCREATE(CShowHtmlDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowHtmlDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowHtmlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowHtmlDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWHTMLDOC_H__6866564B_7E11_11D7_886E_8A3E70C5F33E__INCLUDED_)
