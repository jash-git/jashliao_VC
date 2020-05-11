// ShowviewDoc.h : interface of the CShowviewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWVIEWDOC_H__01745AE4_3C9B_4EBA_9BEB_80A5B9AF54A5__INCLUDED_)
#define AFX_SHOWVIEWDOC_H__01745AE4_3C9B_4EBA_9BEB_80A5B9AF54A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowviewDoc : public CDocument
{
protected: // create from serialization only
	CShowviewDoc();
	DECLARE_DYNCREATE(CShowviewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowviewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowviewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowviewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWVIEWDOC_H__01745AE4_3C9B_4EBA_9BEB_80A5B9AF54A5__INCLUDED_)
