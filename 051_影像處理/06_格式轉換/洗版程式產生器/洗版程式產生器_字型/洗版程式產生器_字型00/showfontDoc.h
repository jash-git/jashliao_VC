// showfontDoc.h : interface of the CShowfontDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWFONTDOC_H__233A6D86_C502_4958_B597_84435E3EFB75__INCLUDED_)
#define AFX_SHOWFONTDOC_H__233A6D86_C502_4958_B597_84435E3EFB75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowfontDoc : public CDocument
{
protected: // create from serialization only
	CShowfontDoc();
	DECLARE_DYNCREATE(CShowfontDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowfontDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowfontDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowfontDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWFONTDOC_H__233A6D86_C502_4958_B597_84435E3EFB75__INCLUDED_)
