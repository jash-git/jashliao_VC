// framviewDoc.h : interface of the CFramviewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FRAMVIEWDOC_H__A01A8A58_81D9_40E0_A7D2_EB71424B5C9A__INCLUDED_)
#define AFX_FRAMVIEWDOC_H__A01A8A58_81D9_40E0_A7D2_EB71424B5C9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFramviewDoc : public CDocument
{
protected: // create from serialization only
	CFramviewDoc();
	DECLARE_DYNCREATE(CFramviewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFramviewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFramviewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFramviewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAMVIEWDOC_H__A01A8A58_81D9_40E0_A7D2_EB71424B5C9A__INCLUDED_)
