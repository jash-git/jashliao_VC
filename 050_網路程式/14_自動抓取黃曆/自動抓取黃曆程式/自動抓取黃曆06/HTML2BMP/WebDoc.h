// WebDoc.h : interface of the CWebDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WEBDOC_H__8974DE71_01BA_4A30_8093_070461B25C9C__INCLUDED_)
#define AFX_WEBDOC_H__8974DE71_01BA_4A30_8093_070461B25C9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWebDoc : public CDocument
{
protected: // create from serialization only
	CWebDoc();
	DECLARE_DYNCREATE(CWebDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWebDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWebDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBDOC_H__8974DE71_01BA_4A30_8093_070461B25C9C__INCLUDED_)
