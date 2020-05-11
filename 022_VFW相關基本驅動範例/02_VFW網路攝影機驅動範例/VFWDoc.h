// VFWDoc.h : interface of the CVFWDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VFWDOC_H__F46F6E1A_91E0_46E1_85B0_451BCCD7365E__INCLUDED_)
#define AFX_VFWDOC_H__F46F6E1A_91E0_46E1_85B0_451BCCD7365E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVFWDoc : public CDocument
{
protected: // create from serialization only
	CVFWDoc();
	DECLARE_DYNCREATE(CVFWDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVFWDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVFWDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVFWDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VFWDOC_H__F46F6E1A_91E0_46E1_85B0_451BCCD7365E__INCLUDED_)
